N = int(input())

deps = {}

for i in range(N):
    S = input().split()
    deps[S[0].lower()] = ' '.join(S[1:])

print(len(deps))

for S in sorted(deps):
    print(deps[S])
