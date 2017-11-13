N = int(input())
maps = {}

for i in range(N):
    S, X0, Y0, DX, DY = input().split()

    maps[S] = (int(X0) + int(DX), int(Y0) + int(DY))

parties = input().split()

for party in parties:
    print(maps[party][0], maps[party][1])
