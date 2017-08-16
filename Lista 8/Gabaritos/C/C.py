transacs = {}

while True:
    I = input().split()

    if I[0] == 'E':
        transacs[I[1]] = I[2]
    elif I[0] == 'R':
        print(transacs.get(I[1], 'Usuário não cadastrado'))
    elif I[0] == 'F':
        break
