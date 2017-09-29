tempo = int(input()) # Tempo em segundos

horas = tempo//3600 #// faz a divisão inteira entre os operandos
tempo -= horas*3600
""" É necessário descontar do tempo inicial o valor calculado em horas,
para calcularmos os minutos. Os segundos serão o que sobrar do tempo """
minutos = tempo//60
tempo -= minutos*60

print(horas, "h:", minutos, "m:", tempo, "s", sep='')
#Mudamos o separador padrão do print, conforme explicado no enunciado da questão
