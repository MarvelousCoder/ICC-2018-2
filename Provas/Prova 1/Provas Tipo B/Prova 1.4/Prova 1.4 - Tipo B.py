n = int(input())
custo = 0
x = int(input())
maior = x
while(n > 1): #Os valores das próximas n-1 casas
    x = int(input())
    custo = custo + (maior - x)
    n -= 1
print(custo)
