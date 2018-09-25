N = int(input())

r_maior_vazao_s = ''
maior_vazao_s = 0

r_maior_tratamento = ''
maior_tratamento = 0

r_maior_percent_pop = ''
maior_percent_pop = 0

r_valor_medio_inv = 0.0

for i in range(N):
    inp = input()
    nome, pop_urb, vazao_efl_s, vazao_efl_c, pop_atend, inv = inp.split()
    pop_urb, vazao_efl_s, vazao_efl_c, pop_atend, inv = [int(pop_urb), float(vazao_efl_s), float(vazao_efl_c), int(pop_atend), float(inv)]

    if vazao_efl_s > maior_vazao_s:
        r_maior_vazao_s = nome
        maior_vazao_s = vazao_efl_s

    if vazao_efl_c > maior_tratamento:
        r_maior_tratamento = nome
        maior_tratamento = vazao_efl_c

    if pop_atend/pop_urb > maior_percent_pop:
        r_maior_percent_pop = nome
        maior_percent_pop = pop_atend/pop_urb

    r_valor_medio_inv += inv

print(r_maior_vazao_s)
print(r_maior_tratamento)
print(r_maior_percent_pop)
print('R$ ' + ('%.2f' % (r_valor_medio_inv/N)))
