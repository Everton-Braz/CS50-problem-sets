#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void){
    //Ask the text
    string text = get_string("Digite o texto aqui: ");
    int count_letters = 0;
    int count_words = 0;
    int count_sentences = 0;
    for (int i = 0; text[i]; i++)
    {
        if (isalnum((unsigned char)text[i]))
        {
            count_letters++;
        }
    }
    for (int i = 0; text[i]; i++)
    {
        if (isspace((unsigned char)text[i]))
        {
            count_words++;
        }
    }
    count_words = count_words + 1;
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences++;
        }
    }
    // printf("Letras: %i\n", count_letters);
    // printf("Palavras: %i\n", count_words);
    // printf("Frases: %i\n", count_sentences);

    float L = ((float)count_letters / count_words) * 100;
    float S = ((float)count_sentences / count_words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    int grade = index;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    // printf("L: %f\n", L);
    // printf("S: %f\n", S);
}
