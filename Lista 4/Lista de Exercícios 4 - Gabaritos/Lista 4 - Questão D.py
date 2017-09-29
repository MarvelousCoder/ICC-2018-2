""" Com raciocínio semelhante à questão 3, se o número digitado for par então
retornaremos a soma de n-2 e chamamos a função novamente passando n-2. Caso o
número digitado for ímpar, retornaremos o próximo par p que seja igual a n - 2e
chamamos a função passando p.
Note que depois que verificarmos se o n digitado pelo usuário é par, todas as
chamadas da função terão como parâmetro um número par.
Continuaremos essas chamadas até que n seja 0, onde terminamos o somatório """
def somatorio(n):
    if(n > 0):
        if(n % 2 == 0): #Caso n seja par
            return (n-2) + somatorio(n-2)
        else: #Caso seja ímpar
            return (n-3) + somatorio(n-3)
    else:
        return 0

n = int(input())
if(n < 0):
    print("-1")
else:
    print(somatorio(n))
