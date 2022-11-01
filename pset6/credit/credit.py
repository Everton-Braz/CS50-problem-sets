from cs50 import get_int
from cs50 import get_string

def main():

 while True:
    cardnumber = get_string("Digite o número do cartão: ")
    try:
        if len(cardnumber) == 13 or len(cardnumber) == 15 or len(cardnumber) == 16:
            break
    except ValueError:
        continue
    return cardnumber

 if len(cardnumber) < 13 or len(cardnumber) < 16:
    print("INVALID")
    exit(0)
 card_num = len(cardnumber)
 sum = 0
 for i in range(len(str(card_num))):
    # Verifica se o digito atual é par, se o resto da divisão por 2 é zero.
    if (i % 2 == 0):
        # Se for par, se o resto da divisão for 0, adicionar (resultado do número do cartão resto por 10) à soma.
        sum = sum + card_num % 10
        # Se não for, multiplicar esse valor por 2 e depois adicionar à soma.
    else:
        # 2 * 9 = 18
        digit = 2 * (card_num % 10)
        # Aqui é preciso separar os digitos, 1 + 8
        # // é divisão por inteiro, enquanto / divide por números quebrados
        sum = sum + digit // 10 + digit % 10

    card_num = card_num // 10
 sum % 10 == 0
 print(sum, card_num, len(cardnumber))

#if (cardnumber )




 #print(int(somaDosMultiplicadosPor2))
 print()

main()
