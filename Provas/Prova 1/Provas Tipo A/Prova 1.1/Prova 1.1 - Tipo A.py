n = int(input())

i = 1
num_divisores = 0
while(i < n):
    if(n % i == 0):
        print(i, end = " ")
    i += 1
print(n)
