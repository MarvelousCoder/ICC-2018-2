def mdc(a, b):#O tamanho máximo da pilha é o MDC da quantidade de figurinhas
    if(b == 0):
        return a
    else:
        return mdc(b, a%b)
""" Coloque dois valores quaisquer nessa função e faça passo a passo cada um
dos retornos até que b seja 0 """
n1, n2 = input().split()
n1, n2 = [int(n1), int(n2)]
print(mdc(n1, n2))
