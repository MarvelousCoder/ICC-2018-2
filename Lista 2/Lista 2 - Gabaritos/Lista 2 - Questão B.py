#Note que poderíamos fazer tudo em função só, mas usaremos duas funções
peso = float(input())
h = float(input())
indice = peso/(h**2)
print("%.2f"%indice)
if(indice < 18.5):
    print("Baixo peso")
elif(indice <= 24.9):
    print("Peso normal")
elif(indice <= 29.9):
    print("Sobrepeso")
    peso_necessario = 24.9*h*h 
    print("%.2f"%(peso-peso_necessario))
    #Peso mínimo necessário será aquele suficiente para atingir IMC 24.9
elif(indice <= 34.9):
    print("Obesidade grau I")
    peso_necessario = 24.9*h*h
    print("%.2f"%(peso-peso_necessario))
elif(indice <= 39.9):
    print("Obesidade grau II")
    peso_necessario = 24.9*h*h
    print("%.2f"%(peso-peso_necessario))
else:
    print("Obesidade grau III")
    peso_necessario = 24.9*h*h
    print("%.2f"%(peso-peso_necessario))
