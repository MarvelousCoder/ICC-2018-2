N = int(input())

convidados = []
for i in range(N):
    convidados += [input()]

print("Cuidado!" if "André" in convidados else "Seguro!")
