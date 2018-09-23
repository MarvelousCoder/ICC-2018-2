def mdc(a, b):
    if(b == 0):
        return a
    else:
        return mdc(b, a%b)

a, b = input().split()
a, b = [int(a), int(b)]
quantidade_mdcs = 0
soma_mdcs = 0

while(a > 0 and b > 0):
    x = mdc(a,b)
    quantidade_mdcs += 1
    soma_mdcs += x
    print(x)
    a, b = input().split()
    a, b = [int(a), int(b)]
print("%.2f"%(soma_mdcs/quantidade_mdcs))
