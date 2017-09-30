frase = input()

final = ""
cont = 0
print(frase[0])
final += frase[0].upper()
for letra in frase[1:]:
    if(cont):
        final = final + letra.upper()
        cont = 0
    else:
        final = final + letra
    if letra == ".":
        cont = 1

print(final)
