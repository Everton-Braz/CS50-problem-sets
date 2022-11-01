#include <cs50.h> //Inclui a bibiotecla CS50
#include <stdio.h> // Inclui a bibiotecla 'Standard Input and Output'

int main(void){
    //Pede ao usúario um número inteiro. Altura da Pirâmide
    int altura;
    do{
    altura = get_int("Positive number: ");
    }
    //Não pode ser menor que 0 e nem maior do que 8
    while (altura < 1 || altura > 8);
    for (int linha = 1; linha <= altura; linha++)
    {
        for (int coluna = 0; coluna < altura; coluna++)
        if (coluna < altura - linha)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
        printf("\n");
    }
}