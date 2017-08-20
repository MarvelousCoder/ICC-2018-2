A = float(input())
maior = A
teste = 0
B = float(input())
if(B > maior):
    maior = B
    teste = 1
C = float(input())
if(C > maior):
    maior = C
    teste = 2
""" Além de sabermos o valor da maior lado, também precisamos saber qual é.
Através da variável teste saberemos qual o maior lado! """

if(teste == 0): #Nesse caso A é o maior lado
    if(maior > B + C or maior == B + C):
        print("NAO FORMA TRIANGULO")
    elif(maior*maior == B*B + C*C):
        print("TRIANGULO RETANGULO")
    elif(A == B and B == C):
        print("TRIANGULO EQUILATERO")
    elif(A == B or A == C or B == C):
        print("TRIANGULO ISOSCELES")
    else:
        print("TRIANGULO ACUTANGULO OU OBTUSANGULO")
elif(teste == 1): #Aqui B é o maior lado
    if(maior > A + C or maior == B + C):
        print("NAO FORMA TRIANGULO")
    elif(maior*maior == A*A + C*C):
        print("TRIANGULO RETANGULO")
    elif(A == B and B == C):
        print("TRIANGULO EQUILATERO")
    elif(A == B or A == C or B == C):
        print("TRIANGULO ISOSCELES")
    else:
        print("TRIANGULO ACUTANGULO OU OBTUSANGULO")
else: #Caso contrário C será o maior
    if(maior > A + B or maior == B + C):
        print("NAO FORMA TRIANGULO")
    elif(maior*maior == B*B + A*A):
        print("TRIANGULO RETANGULO")
    elif(A == B and B == C):
        print("TRIANGULO EQUILATERO")
    elif(A == B or A == C or B == C):
        print("TRIANGULO ISOSCELES")
    else:
        print("TRIANGULO ACUTANGULO OU OBTUSANGULO")
""" Podemos usar elif, visto que não é possivel entrar com raiz quadrada
no Python Shell, seja x o valor de dois lados do triângulo e y do terceiro.
Para que y^2 seja igual a 2*(x^2), é necessário que y seja igual a
(2^(1/2)) * x"""
    
