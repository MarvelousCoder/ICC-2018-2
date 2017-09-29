m, d = input().split()
m, d = [int(m), int(d)]

if(m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12):
    ndays = 31
elif(m == 2):
    ndays = 28
else:
    ndays = 30

print(((d - 1) + ndays - 1)//7 + 1)
""" Você também pode obter o número de colunas analisando caso por caso o valor
de d, considerando quantos dias cada mês têm. """
