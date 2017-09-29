x = int(input())
maior = x
quantidade = 0
soma = 0
"""Enquanto x não for 0, vamos somando x com o valor anterior de soma,
incrementando a quantidade e verificando se x é maior do que o maior x que
já temos. Depois lemos o próximo inteiro da sequência. """
while(x != 0): 
    soma += x
    quantidade += 1
    if(x > maior):
        maior = x
    x = int(input())
if(quantidade > 0):
    print(quantidade)
    print(maior)
    print("Média: %.2f"%(soma/quantidade))
else: #Caso o primeiro número lido já seja 0
    print("0\n0\n0.00")
