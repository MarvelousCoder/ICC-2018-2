n = int(input())
x, y = input().split()
x, y = [int(x), int(y)]
soma = 0
while(y > 0):
        if(x % 2 != 0):
            soma += x
            y -= 1
        x += 1
maior = soma
menor = soma
print(soma)
"""Pegamos a soma da 1º dupla de X e Y como maior e menor soma, depois vamos
comparando com as somas das outras duplas. """
while(n > 1): #Lemos os próximos n-1 casos de teste
    x, y = input().split()
    x, y = [int(x), int(y)]
    soma = 0
    while(y > 0):#While *
        if(x % 2 != 0):
            soma += x
            y -= 1
        x += 1
    if(soma > maior):
        maior = soma
    if(soma < menor):
        menor = soma
    print(soma)
    n -= 1
print(maior)
print(menor)
""" Para o while *, se o atual x for ímpar, então somamos ao valor de soma e
atribuímos a variável soma. Também decrementamos o valor de y, pois dos Y
ímpares consecutivos já atribuímos 1 a soma. Depois incrementamos x e continua
mos verificando. Após o while * imprimimos a soma."""
""" Usando for (complete colocando para imprimir a maior e a menor soma):
for i in range(0, n):
    x, y = input().split()
    x, y = [int(x), int(y)]
    soma = 0
    if(x % 2 == 0):
        for x in range(x, x+2*y):
            if(x%2 != 0):
                soma += x
        print(soma)
    else:#Se x for ímpar então precisamos somar y-1 ímpares a partir de x
        for x in range(x, x+2*y - 1):
            if(x%2 != 0):
                soma += x
        print(soma) """
