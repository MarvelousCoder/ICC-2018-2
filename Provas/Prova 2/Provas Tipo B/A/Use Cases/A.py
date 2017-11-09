mix = input()
new_mix = ""

for c in mix:
    if c.isupper():
        new_mix += "_"
    new_mix += c

splitted = new_mix.split("_")
print("_".join([x.capitalize() for x in splitted if x != ""]))
# você também pode fazer algo como
# while "" in splitted: splitted.remove("")
# para remover os - repetidos :)
