#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    //Ask for the user a value in dollar
    float Troco;
    do
    {
    Troco = get_float("Digite o troco: ");
    }
    //O troco não pode ser negativo
    while (Troco <= 0);
    
    int centavos;
    centavos = round(Troco * 100); //Arredondamento do valor em reias para centavos
    //printf("%i\n", centavos);

    int moedade25;
    int moedade10;
    int moedade5;
    int moedade1;
    int resto1;
    int resto2;
    int resto3;

    moedade25 = centavos / 25;
    resto1 = centavos % 25;
    //printf("%i\n", resto1);

    moedade10 = resto1 / 10;
    resto2 = resto1 % 10;
    //printf("%i\n", moedade10);

    moedade5 = resto2 / 5;
    resto3 = resto2 % 5;
    //printf("%i\n", moedade5);

    moedade1 = resto3 % 5;

    int soma = moedade25 + moedade10 + moedade5 + moedade1;
    printf("Quantidade de moedas: %i\n", soma);
}







