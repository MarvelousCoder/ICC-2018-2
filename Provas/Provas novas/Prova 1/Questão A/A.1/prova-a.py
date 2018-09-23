num = int(input())

diferenca = 0
maior = 0
maiorNome = ""
menor = 0
menorNome = ""
for i in range(num):
    nome, vazChuva, vazSeca = input().split()
    vazChuva, vazSeca = [float(vazChuva), float(vazSeca)]

    diferenca += (vazChuva-vazSeca)/num

    if i == 0:
        maior = vazChuva
        maiorNome = nome
        menor = vazSeca
        menorNome = nome
    else:
        if vazChuva > maior:
            maior = vazChuva
            maiorNome = nome
        if vazSeca < menor:
            menor = vazSeca
            menorNome = nome
if num != 0:
    print(maiorNome)
    print(menorNome)
print("%.3f" %(diferenca))
