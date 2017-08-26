t = int(input())
while(t > 0):
    a, n = input().split()
    a, n = [int(a), int(n)]
    soma = 0
    x = a
    while(x < a + n - 1):
        soma += x
        print(x, end= " ")
        x += 1
    soma += x
    print(x)
    print(soma)
    t -= 1 #Decrementamos t

"""Temos que somar os próximos N números a partir de A. Logo, somamos o valor
atual de soma com o anterior + o próximo A (que nesse caso é x) e
incrementamos o valor de x (para termos o valor do próximo A). Para imprimir
a soma usamos o caractere \n, pois ela deve ser impressa na próxima linha. """

""" Usando for:
for y in range(0, t):
        a, n = input().split()
        a, n = [int(a), int(n)]
        soma = 0
        for x in range(a, a+n):
            soma += x
            print(x, end= " ")
        print("\nSoma= %d"%soma) """
