def fatorial(k):
    if(k == 0 or k == 1):
        return 1
    else:
        return k*fatorial(k-1)

k = int(input())
print(fatorial(k))
while(k >= 0):
    k = int(input())
    if(k >= 0):
        x = fatorial(k)
        print(x)

