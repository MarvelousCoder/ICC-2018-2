F, P = [int(x) for x in input().split()]

fatias = list(range(F))
fatias[P] = "*"

for i in range(F):
    N, E = input().split()
    E = int(E)

    del fatias[E]
    if "*" not in fatias:
        print(N)
        break
