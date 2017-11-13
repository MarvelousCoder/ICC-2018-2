N = int(input())

corrupt = {}

for i in range(N):
    S = input().split()
    corrupt[S[0]] = S[1:]

R = input().split()

# verifique o gabarito da questão F da lista 7
request = sorted(list(filter(lambda c: list(filter(lambda d: d in R, corrupt[c])), corrupt.keys())), key=str.lower)

print(' '.join(request))
