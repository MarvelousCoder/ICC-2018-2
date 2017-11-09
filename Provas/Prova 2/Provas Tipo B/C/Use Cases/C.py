N = int(input())
maps = {}

for i in range(N):
    S, X0, Y0, XF, YF = input().split()

    maps[S] = (int(XF) - int(X0), int(YF) - int(Y0))

parties = input().split()

for party in parties:
    print(maps[party][0], maps[party][1])
