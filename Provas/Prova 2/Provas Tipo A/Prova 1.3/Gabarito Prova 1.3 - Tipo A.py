N = int(input())

T = {}

for i in range(N):
    O, A = input().split()
    T[O] = A

F = input()
R = []

for word in F.split():
    if word in T:
        R.append(T[word])
    else:
        R.append(word)

print(" ".join(R))
