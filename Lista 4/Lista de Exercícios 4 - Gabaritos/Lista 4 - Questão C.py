""" Se o número for par imprimimos na tela e chamamos a função recursivamente,
passando como parâmetro n-2(o próximo número par menor que o atual n). Caso o
número passado inicialmente como parâmetro seja ímpar, então apenas chamamos a
função de forma recursiva, passando n-1 como parâmetro. Quando n for negativo,
finalizamos a função """
def imprime_pares(n):
    if(n >= 2):
        if(n%2 == 0):
            print(n)
            imprime_pares(n-2)
        else:
            imprime_pares(n-1)
    else:
        return

n = int(input())
imprime_pares(n)

        
