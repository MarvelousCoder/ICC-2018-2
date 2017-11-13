""" Seja k o número de palavras que são conhecidas por Charmander e Pikachu.
Note que os pokémons processarão as k palavras primeiro. É fácil ver que se k
for ímpar, então Charmander terá uma palavra de vantagem. Assim, se n for menor
ou igual a m, Charmander perde. Caso contrário ele vence.
"""

n, m = input().split()
n, m = [int(n), int(m)]

char = []
pikachu = []
k = 0 # Número de palavras que tanto pikachu quanto charmander conhecem
for i in range(0,n):
    char.append(input())
for i in range(0, m):
    pikachu.append(input())
       
for i in pikachu:
    if i in char:
        k += 1

if (k % 2 != 0):
    n = n + 1

if(n <= m):
    print("NAO")
    print(char[0])
else:
    print("SIM")
    print(char[0])
