# remove pontuação
trecho = input().replace(".", "").replace(",", "").replace("!", "").replace("?", "").replace(":", "")

d = {}

for word in trecho.split():
    word = word.lower()

    if word in d:
        d[word] = d[word] + 1
    else:
        d[word] = 1

for word in sorted(d, key=lambda x: (d[x],x), reverse=True):
    print(word.capitalize(), d[word])
