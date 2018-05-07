def Fibonacci(n):
    if(n == 1 or n == 2):
        return 1
    else:
        return Fibonacci(n-1) + Fibonacci(n-2)

k = int(input())
numeros_lidos = 0
media = 0
maior = 0
while(k > 0):
    x = Fibonacci(k)
    if(x > maior):
        maior = x
    numeros_lidos += 1
    media += k
    if(k % 2 == 0):
        if(x % 2 == 0):
            print(x + k)
        else:
            print(x * k)
    else:
        if(x % 2 == 0):
            print(x - k)
        else:
            print(x//k)
    k = int(input())
print("%.2f"%(media/numeros_lidos))
print(maior)
