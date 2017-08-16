def imc(h, peso_pessoa):
    indice = peso_pessoa/(h**2)
    print("%.2f"%indice)
    return indice
        
def classificacao(indice, peso_pessoa, h):
    if(indice < 18.5):
        print("Baixo peso")
    elif(indice <= 24.9):
        print("Peso normal")
    elif(indice <= 29.9):
        print("Sobrepeso")
        peso_necessario = 24.9*h*h 
        print("%.2f"%(peso_pessoa-peso_necessario))
        #Peso mínimo necessário será aquele suficiente para atingir IMC 24.9
    elif(indice <= 34.9):
        print("Obesidade grau I")
        peso_necessario = 24.9*h*h
        print("%.2f"%(peso_pessoa-peso_necessario))
    elif(indice <= 39.9):
        print("Obesidade grau II")
        peso_necessario = 24.9*h*h
        print("%.2f"%(peso_pessoa-peso_necessario))
    else:
        print("Obesidade grau III")
        peso_necessario = 24.9*h*h
        print("%.2f"%(peso_pessoa-peso_necessario))

#Note que poderíamos fazer tudo em função só, mas usaremos duas funções
peso = float(input())
altura = float(input())
indice_pessoa = imc(altura, peso)
classificacao(indice_pessoa, peso, altura)
