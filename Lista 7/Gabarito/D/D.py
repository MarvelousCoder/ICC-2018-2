N = int(input())

list_of_problems = []

for i in range(N):
    P, S, D = input().split()
    D = int(D)

    list_of_problems.append((S, D))

# from question B
o_list = sorted(list_of_problems, key=lambda x: -x[1])

for solution in o_list:
    print(solution[0], end="")
print() # for newline
