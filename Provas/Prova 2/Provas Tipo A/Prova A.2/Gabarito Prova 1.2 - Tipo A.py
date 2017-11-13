perms = (   lambda a,b,c: (c,b,a),
            lambda a,b,c: (a,c,b),
            lambda a,b,c: (b,a,c)
        )

org = ('A', 'B', 'C')

N = int(input())

for i in range(N):
    p = int(input())
    org = perms[p-1](*org)

print(" ".join(org))
