def fatorial(n):
    fatorial = 1
    while(n > 0):#Quando n chegar ao valor 0 o loop será terminado
        fatorial = fatorial * n
        n -= 1
    return fatorial

n = int(input())
m = int(input())
print(fatorial(n), end=" ") #Trocamos o argumento padrão do end
print(fatorial(m))
#Também podemos fazer tudo com um print: print(fatorial(n), fatorial(m))
"""Alternativamente usando o laço de repetição for:
def fatorial(n):
    fatorial = 1
    for i in range(1,n+1): #O valor i começará em 1 e irá até n
         fatorial *= i
    return fatorial
O segundo argumento do for é sempre uma lista. A função range gera uma lista
de números que iniciam no primeiro argumento e terminam no número anterior ao
segundo argumento.
Exemplo: range(0,3) gera a lista [0,1,2] """
