N = int(input())

products = []
for i in range(N):
    products = [input()] + products

print(", ".join(products))
