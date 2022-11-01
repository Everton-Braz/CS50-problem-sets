#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    //Ask for the user a card number valid
    long cardnumber;
    do
    {
    cardnumber = get_long("Digite o número de seu cartão de crédito:");
    }
    while (cardnumber < 0);

    int d16 = cardnumber % 10;
    int d15 = cardnumber % 100 / 10 * 2;
    if (d15 > 10)
    {
        d15 = (d15 / 10) + (d15 % 10);
    }
    int d14 = cardnumber % 1000 / 100;
    int d13 = cardnumber % 10000 / 1000 * 2;
        if (d13 > 10)
    {
        d13 = (d13 / 10) + (d13 % 10);
    }
    int d12 = cardnumber % 100000 / 10000;
    int d11 = cardnumber % 1000000 / 100000 * 2;
        if (d11 > 10)
    {
        d11 = (d11 / 10) + (d11 % 10);
    }
    int d10 = cardnumber % 10000000 / 1000000;
    int d09 = cardnumber % 100000000 / 10000000 * 2;
        if (d09 > 10)
    {
        d09 = (d09 / 10) + (d09 % 10);
    }
    int d08 = cardnumber % 1000000000 / 10000000;
    int d07 = cardnumber % 10000000000 / 100000000 * 2;
        if (d07 > 10)
    {
        d07 = (d07 / 10) + (d07 % 10);
    }
    int d06 = cardnumber % 100000000000 / 1000000000;
    int d05 = cardnumber % 1000000000000 / 100000000000 * 2;
        if (d05 > 10)
    {
        d05 = (d05 / 10) + (d05 % 10);
    }
    int d04 = cardnumber % 10000000000000 / 1000000000000;
    int d03 = cardnumber % 100000000000000 / 10000000000000 * 2;
        if (d03 > 10)
    {
        d03 = (d03 / 10) + (d03 % 10);
    }
    int d02 = cardnumber % 1000000000000000 / 100000000000000;
    int d01 = cardnumber % 10000000000000000 / 1000000000000000 * 2;
        if (d01 > 10)
    {
        d01 = (d01 / 10) + (d01 % 10);
    }

    int soma1 = d15 + d13 + d11 + d09 + d07 + d05 + d03 + d01;
    int soma2 = soma1 + d16 + d14 + d12 + d10 + d08 + d06 + d04 + d02;

    //digito2 = cardnumber % 100 / 10;
    //digito3 = cardnumber %


    // printf("%i\n", d16);
    // printf("%i\n", d15);
    // printf("%i\n", d14);
    // printf("%i\n", d13);
    // printf("%i\n", d12);
    // printf("%i\n", d11);
    // printf("%i\n", d10);
    // printf("%i\n", d09);
    // printf("%i\n", d08);
    // printf("%i\n", d07);
    // printf("%i\n", d06);
    // printf("%i\n", d05);
    // printf("%i\n", d04);
    // printf("%i\n", d03);
    // printf("%i\n", d02);
    // printf("%i\n", d01);
    // printf("%i\n", soma1);
    // printf("%i\n", soma2);


    //soma2 = soma2 % 10;

    int valido = 1;

    if (soma2 % 10 == 0)
    {
        valido = 0;
    }

    int amex = cardnumber / 10000000000000;
    int mastercard = cardnumber / 100000000000000;
    int visa = cardnumber / 1000000000000000;

    if ((valido == 0 && amex == 34) || (valido == 0 && amex == 37))
    {
        printf("AMEX\n");
    }
    else if((valido == 0 && mastercard == 51) ||
    (valido == 0 && mastercard == 52) ||
    (valido == 0 && mastercard == 53) ||
    (valido == 0 && mastercard == 54) ||
    (valido == 0 && mastercard == 55))
    {
        printf("MasterCard\n");
    }
    else if(valido == 0 && visa == 4)
    {
        printf("Visa\n");
    }
    else{
        printf("Inválido\n");
    }
    //printf("Amex:%i\n", amex);
    //printf("MasterCard:%i\n", mastercard);
    //printf("Visa:%i\n", visa);
}
