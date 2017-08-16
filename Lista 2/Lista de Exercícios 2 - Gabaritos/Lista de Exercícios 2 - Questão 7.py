def Fibonacci(n):
    if(n == 1 or n == 2):
        return 1
    else:
        return Fibonacci(n-1) + Fibonacci(n-2)
""" Para a função recursiva Fibonacci foi aplicada a definição, da mesma
forma para o cálculo do fatorial vamos fazendo chamadas de funções dentro da
chamada da função e retornando até que n chegue a 1 ou 2 """

n = int(input())
quantidade_casais = Fibonacci(n)
if(quantidade_casais % 2 == 0): #Nesse caso a quantidade é par
    print(quantidade_casais)
    print(Fibonacci(n-1))
else:
    print(quantidade_casais)
""" Note que a quantidade de casais que irão nascer no próximo mês, pela
definição de Fibonacci é justamente a quantidade de casais do mês anterior,
ou seja, Fibonacci(n-1). Pois Fibonacci(n+1) = Fibonacci(n) + Fibonacci(n-1),
assim Fibonacci(n+1) - Fibonacci(n) = Fibonacci(n-1) """
