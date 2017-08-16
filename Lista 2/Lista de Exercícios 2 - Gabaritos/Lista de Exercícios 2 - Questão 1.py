def multiplica_string(variavel_string, entrada):
    print(variavel_string*entrada) #Usando '*' imprimimos 'texto' x vezes
#Note que a identação determina o escopo da função multiplica_string
texto = "Eric, the half a bee. "
x = int(input())
multiplica_string(texto, x)
