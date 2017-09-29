import math #Importamos a bilioteca math para poder usar a função math.sqrt()

x1, y1 = input().split()
x2, y2 = input().split()
x1, y1 = [float(x1), float(y1)]
x2, y2 = [float(x2), float(y2)]
z = complex(input())

distancia_quadrado = ((x2 - x1) ** 2) + ((y2 - y1) ** 2)
# ** operador de exponenciação
distancia = math.sqrt(distancia_quadrado)
#sqrt é a raiz quadrada, função da biblioteca math
#Note que também poderiamos usar distancia = distancia_quadrado ** (1/2)
print("%.4f"%distancia)
z = z.real**2 + z.imag**2
#z.real acessa a parte real do número, e z.imag a parte imaginária
print("%.4f"%(math.sqrt(z)))
