inp = input()
while inp != 'fim':
    numbers = ''.join([c if c.isdigit() else ' ' for c in inp]).split()
    symbols = ''.join([c if not c.isdigit() else ' ' for c in inp]).split()
    for i, j in zip(numbers, symbols):
        for k in range(int(i)):
            print(j, end='')
    print()
    inp = input()
