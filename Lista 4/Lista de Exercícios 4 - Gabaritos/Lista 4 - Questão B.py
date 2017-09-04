def entrada_dados(maior, numero):
    if(numero > maior):
        maior = numero
    return maior

numero = int(input())
maior = numero
x = numero
#Atribuimos maior como o primeiro numero lido e chamamos a função 9 vezes
maior = entrada_dados(maior, int(input()))
maior = entrada_dados(maior, int(input()))
maior = entrada_dados(maior, int(input()))
maior = entrada_dados(maior, int(input()))
maior = entrada_dados(maior, int(input()))
maior = entrada_dados(maior, int(input()))
maior = entrada_dados(maior, int(input()))
maior = entrada_dados(maior, int(input()))
maior = entrada_dados(maior, int(input()))
print(maior)
if(maior % x == 0):
    print(x)
