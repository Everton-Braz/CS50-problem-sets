# from cs50 import get_float

def main():

 while True:
    troco = float(input("Digite o troco: "))
    if troco > 0:
        break
    return troco

#Quero o troco em centavos, por isso estou mulpitpicando por 100.
 centavos = round(troco * 100)
 #print(centavos)

 moeda25 = centavos / 25
 resto1 = centavos % 25

 moeda10 = resto1 / 10
 resto2 = resto1 % 10

 moeda5 = resto2 / 5
 resto3 = resto2 % 5

 moeda1 = resto3 % 5

 soma = moeda25 + moeda10 + moeda5 + moeda1
 print(f"Quantidade de moedas necessárias para o troco: {round(soma)}")


main()


