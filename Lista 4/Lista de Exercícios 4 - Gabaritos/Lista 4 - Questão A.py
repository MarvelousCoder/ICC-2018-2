def compare(x, y):
    if(x > y):
        return 1
    elif(x == y):
        return 0
    return -1

x = int(input())
y = int(input())
retorno = compare(x, y)
if(retorno == 1):
    print("x e maior que y")
elif(retorno == 0):
    print("x e igual a y")
else:
    print("x e menor que y")
