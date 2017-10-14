computed = dict()

def Fack(x,y):
    if not (x,y) in computed:
        if x == 0:
            computed[x,y] = y+1
        elif x == 1:
            computed[x,y] = y+2
        elif x == 2:
            computed[x,y] = 2*y+3
        elif y == 0:
            computed[x,y] = Fack(x-1, 1)
        else:
            computed[x,y] = Fack(x-1, Fack(x, y-1))

    return computed[x,y]

X, Y = [int(x) for x in input().split()]

print(Fack(X, Y))
