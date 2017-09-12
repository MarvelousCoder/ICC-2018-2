def fatorial(num):
    if(num == 1 or num == 0):
        return 1
    else:
        return num*fatorial(num-1)

a,b = input().split()
a,b = [int(a), int(b)]

print(fatorial(a) + fatorial(b))
