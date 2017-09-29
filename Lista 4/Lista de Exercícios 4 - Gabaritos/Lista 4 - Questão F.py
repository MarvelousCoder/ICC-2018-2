def mdc(a, b):
    if(b == 0):
        return a
    else:
        return mdc(b, a%b)

def mmc(a,b):
    if(a == 0 or b == 0):
        return 0
    else:
        minimo_multiplo = (a*b)//mdc(a,b)
    return minimo_multiplo
#O mmc(a,b) * mdc(a,b) = a*b

def entrada():#Vamos ler valores enquanto os dois forem maiores ou iguais a zero
    num1, num2 = input().split()
    num1, num2= [int(num1), int(num2)]
    if(num1 < 0 or num2 < 0):
        return
    else:#Escrevemos na tela o mmc e lemos os próximos números
        print(mmc(num1, num2))
        entrada()

entrada()
