#coding: utf-8

N = int(input())
O = input().split()
# copia a lista O, sem usar a mesma referência
F = O[:]

for i in range(5):
    [B, D, Q] = input().split()
    Q = int(Q)
    # inverta o valor se vamos mover para a esquerda
    Q = -Q if D == "E" else Q

    # encontre o índice local de B na lista
    indexOfB = F.index(B)
    newIndexOfB = indexOfB + Q
    # remova ela da posição atual
    del F[indexOfB]
    # insira na posição atualizada
    F[newIndexOfB:newIndexOfB] = [B]

C = 0
for i in range(N):
    if F[i] != O[i]:
        C += 1

print(C)
