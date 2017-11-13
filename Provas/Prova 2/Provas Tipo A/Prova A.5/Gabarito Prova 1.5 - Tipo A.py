Xe, Ye = [int(x) for x in input().split()]
Xd, Yd = [int(x) for x in input().split()]
Xo, Yo = [int(x) for x in input().split()]

if Xe <= Xo <= Xd and Ye <= Yo <= Yd:
    print("Cuidado!")
else:
    print("Seguro!")
