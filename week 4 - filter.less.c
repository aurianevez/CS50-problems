#include "helpers.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop that goes oever the row
    for (int i = 0; i < height; i++)
    {
        //neated loop that goes oever the collumn
        for (int j = 0; j < width; j++)
        {
            // average + round of the pixel's value RGB
            //CAREFUL you can't divid a float by an integer !! so /3.0000 and not 3 !!!!!!
            int newvalue = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0000);

            //set the color value
            image[i][j].rgbtRed = newvalue;
            image[i][j].rgbtGreen = newvalue;
            image[i][j].rgbtBlue = newvalue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop that goes oever the row
    for (int i = 0; i < height; i++)
    {
        //neated loop that goes oever the column
        for (int j = 0; j < width; j++)
        {
            //defining new value rgb for speia
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            //seting color value
            if (sepiaRed > 255)
            {
                sepiaRed = 255;

            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;

            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            else
            {
                image[i][j].rgbtRed = sepiaRed;
                image[i][j].rgbtGreen = sepiaGreen;
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }

    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop that goes over the row
    for (int i = 0; i < height; i++)
    {
        //neated loop that goes over the column
        for (int j = 0; j < width / 2 ; j++)
        {
            if (width % 2 == 0)
            {
                RGBTRIPLE tmp = image[i][width - 1 - j];
                image[i][width - 1 - j] = image [i][j];
                image [i][j] = tmp;
            }

            if (width % 2 != 0)
            {
                if (j == (width - 1) / 2)
                {
                    image[i][j] = image [i][j];
                }

                else
                {
                    RGBTRIPLE tmp = image[i][width - 1 - j];
                    image[i][width - 1 - j] = image [i][j];
                    image [i][j] = tmp;
                }
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));


    //loop that goes over the row
    for (int i = 0; i < height; i++)
    {
        //neated loop that goes over the column
        for (int j = 0; j < width; j++)
        {
            // for pixel in the center
            if (i != 0 && j != 0 && i != height - 1 && j != width - 1)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                    image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                                    image[i - 1][j + 1].rgbtRed) / 9.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen +
                                      image[i + 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen +
                                      image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 9.000);
                int newblue = round((image[i][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue
                                     + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue
                                     + image[i - 1][j + 1].rgbtBlue) / 9.000);

                //storying new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }


            // pixel in the top left corner
            if (i == 0 && j == 0)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed +
                                    image[i][j + 1].rgbtRed) / 4.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen +
                                      image[i][j + 1].rgbtGreen) / 4.000);
                int newblue = round((image[i][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue +
                                     image[i][j + 1].rgbtBlue) / 4.000);

                //storing new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }


            // pixel in the top right corner
            if (i == 0 && j == width - 1)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                    image[i + 1][j].rgbtRed) / 4.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                      image[i + 1][j].rgbtGreen) / 4.000);
                int newblue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                     image[i + 1][j].rgbtBlue) / 4.000);

                //storing new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }


            // bottom left corner
            if (i == height - 1 && j == 0)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                    image[i][j + 1].rgbtRed) / 4.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                      image[i][j + 1].rgbtGreen) / 4.000);
                int newblue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                     image[i][j + 1].rgbtBlue) / 4.000);

                //storing new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }



            // bottom right corner
            if (i == height - 1 && j == width - 1)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed +
                                    image[i][j - 1].rgbtRed) / 4.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                                      image[i][j - 1].rgbtGreen) / 4.000);
                int newblue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                                     image[i][j - 1].rgbtBlue) / 4.000);

                //storing new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }

            // top edge
            if (i == 0 && j != 0 && j != width - 1)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                    image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen
                                      + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.000);
                int newblue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                     image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.000);

                //storing new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }


            // bottom edge
            if (i == height - 1 && j != 0 && j != width - 1)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i - 1][j].rgbtRed +
                                    image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed) / 6.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                      image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.000);
                int newblue = round((image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                                     image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.000);

                //storing new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }


            // left edge
            if (i != 0 && i != height - 1 && j == 0)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed +
                                    image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen
                                      + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.000);
                int newblue = round((image[i][j].rgbtBlue + image[i - 1] [j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue +
                                     image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.000);

                //storing new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }


            // right edge
            if (i != height - 1 && i != 0 && j == width - 1)
            {
                // new value
                int newred = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed +
                                    image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6.000);
                int newgreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen
                                      + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6.000);
                int newblue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue +
                                     image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6.000);

                //storing new value in temporary array
                temp[i][j].rgbtRed = newred;
                temp[i][j].rgbtGreen = newgreen;
                temp[i][j].rgbtBlue = newblue;
            }

        }

    }

    //transfering temp to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = temp[i][j];

        }
    }

    return;
    free(temp);

}
