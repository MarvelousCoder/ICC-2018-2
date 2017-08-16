def fatorial(num):
    if (num == 1 or num == 0):
        return 1
    else:
        return num*fatorial(num-1)
""" Após fazer as subtrações, quando num chegar a 1 então terminaremos as
chamadas, pois não há necessidade de fazer fatorial de 0. Considerando, é claro,
que o num seja maior que 1, caso seja 0 ou 1 então já retornaremos 1.
Enquanto num for maior que 1, precisamos fazer num*fatorial(num-1) e após
finalizar todos as chamadas de funções encadeadas teremos o fatorial de num."""

num1 = int(input())
num2 = int(input())
print("%d! + %d! ="%(num1,num2), fatorial(num1) + fatorial(num2))
