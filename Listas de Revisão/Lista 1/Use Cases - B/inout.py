i = 0
while True:
    filename = str(i) + '.in'
    print(filename + ':')
    with open(filename, 'w') as f:
        inp = input()
        while inp != '':
            f.write(inp)
            f.write('\n')
            inp = input()

    filename = str(i) + '.out'
    print(filename + ':')
    with open(filename, 'w') as f:
        inp = input()
        while inp != '':
            f.write(inp)
            f.write('\n')
            inp = input()

    print('next file?[y/n]')
    inp = input()
    if inp == 'n':
        break
    i += 1
    
        
