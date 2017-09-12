n = int(input())

i = 1
num_divisores = 0
soma_divisores = 0
while(i < n):
    if(n % i == 0):
        num_divisores += 1
        soma_divisores += i
        print(i, end = " ")
    i += 1
num_divisores += 1
soma_divisores += n
print(n)
print(soma_divisores)
print(num_divisores)
