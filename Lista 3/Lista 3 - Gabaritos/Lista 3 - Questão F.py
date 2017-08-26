n1, n2 = input().split()
n1, n2 = [int(n1), int(n2)]

while (n2 is not 0):
    n1,n2 = n2,n1%n2
""" Equivalentemente, podemos usar uma variável auxiliar:
resto = 1
while(resto != 0):
    resto = n1 % n2
    n1 = n2
    n2 = resto
"""
print(n1)
