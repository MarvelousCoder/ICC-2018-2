n = int(input())

m = 1
while(m <= 1000):
    i = 2 #Começamos com 2 para testar se n*m + 1 não é primo
    while(i < n*m + 1):
        if((n*m + 1) % i == 0):#Caso n*m+1 não seja primo
            print(m)
            m = 1001 #Interrompemos o primeiro loop
            break #Interrompemos o segundo loop
        i += 1 #Vamos incrementando 1 até n*m, para descobrir se n*m+1 é primo
    m += 1
