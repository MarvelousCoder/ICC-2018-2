def entrada_dados(maior):
    numero = int(input())
    if(numero > maior):
        maior = numero
    return maior

numero = int(input())
maior = numero
x = numero
#Atribuimos maior como o primeiro numero lido e chamamos a função 9 vezes
maior = entrada_dados(maior)
maior = entrada_dados(maior)
maior = entrada_dados(maior)
maior = entrada_dados(maior)
maior = entrada_dados(maior)
maior = entrada_dados(maior)
maior = entrada_dados(maior)
maior = entrada_dados(maior)
maior = entrada_dados(maior)
print(maior)
if(maior % x == 0):
    print("%d divide %d"%(x, maior))
