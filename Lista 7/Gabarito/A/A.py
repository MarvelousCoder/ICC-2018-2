N = int(input())

personal = {}

for i in range(N):
    T, P = input().split()

    personal[T] = P

F = input().split()

out = []

for word in F:
    if word in personal:
        out.append(personal[word])

if len(out) == 0:
    print("Tudo bem!")
else:
    print(' '.join(out))
