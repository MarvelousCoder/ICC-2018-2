N = int(input())

M = []
for i in range(N):
    M.append(input().split())

for i in reversed(range(N)):
    for j in range(N):
        # se pudermos deixar algo cair
        if M[i][j] == ".":
            # e tiver algo em cima
            if i-1 >= 0 and M[i-1][j] == "o":
                M[i][j] = "o"
                M[i-1][j] = "."

for i in range(N):
    print(" ".join(M[i]), end="")
    print()
