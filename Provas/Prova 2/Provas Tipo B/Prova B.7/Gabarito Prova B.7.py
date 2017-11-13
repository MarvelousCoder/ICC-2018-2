N = int(input())

def parseHour(str):
    return int(str.replace(":", ""))

workers = {}

for i in range(N):
    S = input().split()
    workers[S[0]] = [parseHour(x) for x in S[1:]]

R = parseHour(input())

request = []
for worker in sorted(workers, key=str.lower):
    if workers[worker][0] <= R <= workers[worker][1]:
        request.append(worker)

print(' '.join(request))
