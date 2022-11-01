#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size <= start_size);
    int years = 0;
    do
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }
    while (start_size < end_size);

    printf("Years: %i\n", years);
}