""" Semelhante as questões 3 e 4, porém na função quadrado_pares quando temos
todos os quadrados dos pares calculados e chegamos ao valor 1 nós chamamos
a função entrada novamente para ler o próximo valor """

def entrada():
    n = int(input())
    if(n == 0): #Se n for 0 então paramos de ler valores do teclado
        return
    else:
        quadrado_pares(n)

def quadrado_pares(n):
    if(n > 1):
        if(n % 2 == 0):
            print("%d^2 = %d"%(n,n**2))
            quadrado_pares(n-2)
        else:
            quadrado_pares(n-1)
    else: #Aqui precisamos ler o próximo valor
        entrada()

entrada()
