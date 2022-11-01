#include <cs50.h>
#include <stdio.h>

int main(void){
    int altura;
    do
    {
     altura = get_int("Número positivo: "); //pede ao usuário um número positivo
    }
    while(altura < 0 || altura > 8);
    for (int linha = 0; linha < altura; linha++)
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
        printf("  ");
        for (int piramide2 = 0; piramide2 < altura; piramide2++)
        if (piramide2 < linha)
        {
            printf("#");
        }
        else
        {
            printf("");
        }
    printf("\n");
    }
}