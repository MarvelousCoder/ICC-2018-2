#coding: utf-8

N = int(input())

servers = []

for i in range(N):
    S, R = input().split()
    R = int(R)

    if R > 80:
        servers.append((S, R))

o_list = sorted(servers, key=lambda x: -x[1])

for server in o_list:
    print(server[0])

if len(o_list) == 0:
    print("Ninguém!")
