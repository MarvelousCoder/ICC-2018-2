a, b = input().split()
a, b = [int(a), int(b)]

if(b == 0):
    print("%d 0 errados"%a)
elif(a - b == 1):
    print("%d %d errados"%(a,b))
elif(b - a == 1):
    print("%d %d ok"%(a,b))
elif(b - a == 0 or a - b == 0):
    print("%d %d ok"%(a,b))
else:
    print("%d %d errados"%(a,b))
