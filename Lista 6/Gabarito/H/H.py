[H, P] = [int(x) for x in input().split()]

E = list(range(H))
E.reverse()

C = []
D = []

def move(n, source, target, idle, steps):
    if n > 0:
        steps = move(n-1, source, idle, target, steps)
        if steps <= 0: return steps

        steps -= 1
        target.append(source.pop())
        if steps <= 0: return steps

        steps = move(n-1, idle, target, source, steps)
        if steps <= 0: return steps

    return steps

move(H, E, D, C, P)

print("%d %d %d" % (len(E), len(C), len(D)))
