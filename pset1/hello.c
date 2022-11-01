#include <stdio.h>
#include <cs50.h> //Adiciona uma biblioteca ao arquivo

int main(void){
     // get_string é uma função específica da biblioteca do CS50!
    string name = get_string("Qual é seu nome? \n");
    printf("Hello,%s \n",name);
}