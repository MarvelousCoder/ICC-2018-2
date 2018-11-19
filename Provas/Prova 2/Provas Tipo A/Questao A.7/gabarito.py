N = int(input())

produtos = []

for i in range(N):
    temp = input().split()
    produtos.append((temp[0], temp[1:]))

tags = input()

requests = list(filter(lambda f: list(filter(lambda tag:
                       tag in tags, f[1])), produtos))

for r in requests:
    print(r[0])
