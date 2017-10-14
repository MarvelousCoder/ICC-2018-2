N = int(input())

plays = []

for i in range(N):
    J, I = input().split()
    I = int(I)

    plays.append((J, I))

current = plays[N-1][1]
while plays[current-1][1] != N:
    current = plays[current-1][1]

print(plays[current-1][0])
