#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Para cada pixel de RGBTRIPLE HxW preciso caucular a media dos valores e atribuir a media aos novos pixels.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float soma = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int média = (round)(soma / 3);
            image[i][j].rgbtBlue = média;
            image[i][j].rgbtGreen = média;
            image[i][j].rgbtRed = média;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
// Sépia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
        for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = .393 * image[i][j].rgbtBlue + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtRed;
            float sepiaGreen = .349 * image[i][j].rgbtBlue + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtRed;
            float sepiaBlue = .272 * image[i][j].rgbtBlue + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtRed;
            sepiaRed = (round)(sepiaRed);
            sepiaGreen = (round)(sepiaGreen);
            sepiaBlue = (round)(sepiaBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}
