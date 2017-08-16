hi, mi, hf, mf = input().split()
hi, mi, hf, mf = [int(hi), int(mi), int(hf), int(mf)]

""" Vamos resolver esse problema por casos.
Note que não é possivel ter um caso em que hf == hi e mf > mi, pois o jogo
tem duração máxima de 24 horas.
"""
if(hf <= hi and mf < mi): #Exemplo: 7 5 6 4 - 22h59m ou 7 5 7 4 - 23h59m
    """Vamos transformar as horas para minutos e retirarmos os minutos
    já calculados assim é possível ter as horas certas nos dois exemplos acima,
    fazendo a divisão inteira por 60 """
    minutos = (60-mi)+mf
    horas = ((24 - hi)+hf) * 60 - minutos
    print("O jogo durou %d hora(s) e %d minuto(s)."%(horas//60, minutos))
elif(hf == hi and mf == mi):
    print("O jogo durou 24 hora(s) e 0 minuto(s).")
elif(hf < hi and mf >= mi): #Exemplo: 7 5 6 5 - 23h0m ou 7 5 6 6 - 23h1m
    horas = (24 - hi) + hf
    print("O jogo durou %d hora(s) e %d minuto(s)."%(horas, mf-mi))
else: # Exemplo: 7 5 8 4 - 0h59m  ou 7 8 9 10 - 2h2m
    """Vamos seguir o mesmo raciocínio para o primeiro caso, aqui teremos
    os casos em que: hi < hf and mi < mf(simples) ou hi < hf and mi >= mf """
    minutoi = hi * 60 + mi
    minutof = hf * 60 + mf
    horas = (minutof - minutoi)//60
    minutos = (minutof - minutoi)%60
    print("O jogo durou %d hora(s) e %d minuto(s)."%(horas, minutos))
    
