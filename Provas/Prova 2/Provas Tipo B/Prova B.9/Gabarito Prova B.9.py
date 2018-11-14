inp = input()
while inp != 'fim':
    cur_char = inp[0]
    count = 0
    for let in inp:
        if let != cur_char:
            print(str(count) + cur_char, end='')
            cur_char = let
            count = 1
        else:
            count += 1
    print(str(count) + cur_char)
    inp = input()
    
