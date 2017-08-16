num_adivinha = int(input())
num = int(input())
while(num != num_adivinha):
    if(num < num_adivinha):
        print("O número correto é maior.")
    elif(num > num_adivinha):#Podemos usar um else aqui também
        print("O número correto é menor.")
    num = int(input())#Lemos o próximo número

print("Parabéns! Você acertou.") 
""" Aqui já vamos ter saido do loop, ou seja, num == num_adivinha.
Logo, o jogador acertou o número. """
