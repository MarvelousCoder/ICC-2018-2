r_maior_media_indc = ''
maior_media_indc = 0

r_menor_indc_pluv = ''
menor_indc_pluv = 0
flag_menor_indc_pluv = True

r_area_media = 0.0
num_bacias = 0

while True:
    inp = input()
    nome, area, indc_verao, indc_outono, indc_inverno, indc_primavera = inp.split()
    area, indc_verao, indc_outono, indc_inverno, indc_primavera = [float(area), int(indc_verao), int(indc_outono), int(indc_inverno), int(indc_primavera)]

    if nome == '0':
        break
    
    indc = [indc_verao, indc_outono, indc_inverno, indc_primavera]
    
    media = sum(indc)/4
    if media > maior_media_indc:
        r_maior_media_indc = nome
        maior_media_indc = media

    menor_indc = min(indc)
    if flag_menor_indc_pluv:
        flag_menor_indc_pluv = False
        menor_indc_pluv = menor_indc
        r_menor_indc_pluv = nome
        
    if menor_indc < menor_indc_pluv:
        r_menor_indc_pluv = nome
        menor_indc_pluv = menor_indc

    r_area_media += area
    num_bacias += 1

print(r_maior_media_indc)
print(r_menor_indc_pluv)
print("%.2f" % (r_area_media/num_bacias))

    
    
