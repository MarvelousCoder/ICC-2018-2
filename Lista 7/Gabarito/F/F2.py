n = int(input())
 
lista = []
 
for i in range(n):
    arquivo, T1, T2, T3, T4 = input().split()
    lista.append((arquivo, [T1, T2, T3, T4]))
 
tags = input().split()
 
 
for arquivo in lista:
    for tag in tags:
        if tag in arquivo[1]:
            print(arquivo[0])
            break
