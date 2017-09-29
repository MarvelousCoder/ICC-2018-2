n = int(input())

a,b = 1,1
for i in range(n-1):
  a,b = b,a+b
fatorial = 1
while(n > 1):
    fatorial = fatorial * n
    n -= 1
if(a % 2 == 0):
    print(a, fatorial, b - a)
else:
    print(a, fatorial)

