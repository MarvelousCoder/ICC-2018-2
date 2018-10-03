N = int(input())

maior_vazao_s_coleta = 0
r_maior_vazao_s_coleta = ''

menor_dbo = 0
r_menor_dbo = ''

flag_first = True

taxa_atendidos = 0.0

for i in range(N):
    inp = input()
    nome, pop_urb, vazao_s_coleta, dbo, pop_atendida = inp.split()
    pop_urb, vazao_s_coleta, dbo, pop_atendida = [int(pop_urb), float(vazao_s_coleta), float(dbo), int(pop_atendida)]
    if flag_first:
        flag_first = False
        
        maior_vazao_s_coleta = vazao_s_coleta
        r_maior_vazao_s_coleta = nome

        menor_dbo = dbo
        r_menor_dbo = nome
    else:
        if dbo < menor_dbo:
            menor_dbo = dbo
            r_menor_dbo = nome

        if maior_vazao_s_coleta < vazao_s_coleta:
            maior_vazao_s_coleta = vazao_s_coleta
            r_maior_vazao_s_coleta = nome

    if pop_urb != 0:
        taxa_atendidos = taxa_atendidos + ((float(pop_urb) - float(pop_atendida))/float(pop_urb))
print(r_maior_vazao_s_coleta)
print(r_menor_dbo)
print('%.2f' % (taxa_atendidos/N))
