F = int(input())
matches = {}

def finish_him(T):
    if matches[T][1]:
        return matches[T][0]
    else:
        return finish_him(matches[T][0])

for i in range(F):
    T, N = input().split()

    matches[T] = (N, True)

while True:
    inp = input().split()

    if inp[0] == 'FINAL':
        print(finish_him(inp[1]))
        break
    else:
        T, F1, F2, W = inp
        matches[T] = (W, False)
