def fibonacci(k):
    if(k == 1 or k == 2):
        return 1
    else:
        return fibonacci(k-1) + fibonacci(k-2)

n = int(input())
soma_k = 0
quantidade = n
while(n > 0):
    k = int(input())
    soma_k += k
    if(k <= 0):
        print("erro")
    else:
        x = fibonacci(k)
        print(x)
        if(x % 2 != 0):
            print(fibonacci(k+1))
    n -= 1
if(quantidade == 0):
    print("0.00")
else:
    print("%.2f"%(soma_k/quantidade))
