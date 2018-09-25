nome = ""

diferenca = 0
maior = 0
maiorNome = ""
menor = 0
menorNome = ""
i = 0
while nome != "FIM":
    nome, vazChuva, vazSeca = input().split()
    vazChuva, vazSeca = [float(vazChuva), float(vazSeca)]

    diferenca += (vazChuva-vazSeca)

    if nome == 'FIM':
        break

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
    i += 1

if i == 0:
    print("0.000")
else:
    print(maiorNome)
    print(menorNome)
    print("%.3f" %(diferenca/i))
