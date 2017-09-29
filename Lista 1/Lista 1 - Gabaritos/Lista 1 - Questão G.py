n = int(input())

print(n)
print(n//100, "nota(s) de R$ 100,00") #Fazemos a divisão inteira de n por 100
n = n%100
""" Pegamos o resto da divisão inteira de n por 100, ou seja, descontamos
as notas de 100 já contabilizadas e fazemos novamente a divisão inteira pela
próxima nota, e assim em diante """
print(n//50, "nota(s) de R$ 50,00")
n = n%50
print(n//20, "nota(s) de R$ 20,00")
n = n%20
print(n//10, "nota(s) de R$ 10,00")
n = n%10
print(n//5, "nota(s) de R$ 5,00")
n = n%5
print(n//2, "nota(s) de R$ 2,00")
n = n%2
print(n//1, "nota(s) de R$ 1,00")
