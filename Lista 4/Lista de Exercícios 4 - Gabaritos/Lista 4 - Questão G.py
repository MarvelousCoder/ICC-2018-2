def concat(a, b):
    if not a:
        return b
    else:
        return a[0:1] + concat(a[1:], b)
def prefix(a, b):
    if (not a) and b:
        return True
    elif (a and b):
        return prefix(a[1:], b[1:])
    else:
        return False
def rev(l):
    if not l:
        return l
    else:
        return concat(rev(l[1:]), l[0:1])

a = input()
b = input()
print(concat(a, b))
print(rev(a))
print(prefix(a, b))
