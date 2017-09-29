x = int(input())
y = int(input())

i = 1
soma = 0
while(i <= y):
    if(i % x == 0):
        print(i)
        soma += i
    else: #Aqui não chegamos ao final da linha
        if(i == y): #Nesse caso i será o último valor a ser impresso
            print(i) #Mas a última linha pode ter menos de x números
            soma += i
        else:
            print(i, end= " ") #Alteramos o argumento padrão do end
            soma += i
    i += 1
print(soma)
""" Quando i for múltiplo de x, então já teremos x valores nessa linha e
devemos começar a escrever na próxima. Caso contrário apenas escrevemos o valor
de i com um espaço em branco. No final devemos incrementar i, para o while. """

""" Alternativamente usando for:
for i in range(1, y+1):
    if(i % x == 0):
        print(i)
    else:
        if(i == y):
            print(i)
        else:
            print(i, end = " ")
"""
