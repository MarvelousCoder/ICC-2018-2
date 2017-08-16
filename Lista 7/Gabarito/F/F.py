N = int(input())

files = []

for i in range(N):
    temp = input().split()
    files.append((temp[0], temp[1:]))

tags = input().split()

request = list(filter(lambda f: list(filter(lambda tag: tag in tags, f[1])), files))

for r in request:
    print(r[0])
