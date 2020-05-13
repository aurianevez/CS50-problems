#include "helpers.h"
#include "math.h"
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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop that goes over the row
    for (int i = 0; i < height; i++)
    {
        //neated loop that goes over the column
        for (int j = 0; j < width / 2; j++)
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
    RGBTRIPLE(*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //centered pixel
            if (i != 0 && j != 0 && i != height - 1 && j != width - 1)
            {
                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;
                //loop for the sum for the average
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                //average

                int newred = round(sumred / 9.000);
                int newgreen = round(sumgreen / 9.000);
                int newblue = round(sumblue / 9.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;

            }

            // top left corner
            if (i == 0 && j == 0)
            {

                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;

                //loop for the sum for the average
                for (int k = i; k <= i + 1; k++)
                {
                    for (int l = j; l <= j + 1; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                int newred = round(sumred / 4.000);
                int newgreen = round(sumgreen / 4.000);
                int newblue = round(sumblue / 4.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;
            }

            //top edge
            if (j != 0 && j != width - 1 && i == 0)
            {
                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;

                //loop for the sum for the average
                for (int k = i; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                int newred = round(sumred / 6.000);
                int newgreen = round(sumgreen / 6.000);
                int newblue = round(sumblue / 6.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;
            }

            // top right corner
            if (i == 0 && j == width - 1)
            {
                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;

                //loop for the sum for the average
                for (int k = i; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                int newred = round(sumred / 4.000);
                int newgreen = round(sumgreen / 4.000);
                int newblue = round(sumblue / 4.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;
            }

            //left edge
            if (j == 0 && i != 0 && i != height - 1)
            {
                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;

                //loop for the sum for the average
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j; l <= j + 1; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                int newred = round(sumred / 6.000);
                int newgreen = round(sumgreen / 6.000);
                int newblue = round(sumblue / 6.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;
            }

            //right edge
            if (j == width - 1 && i != 0 && i != height - 1)
            {
                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;

                //loop for the sum for the average
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                int newred = round(sumred / 6.000);
                int newgreen = round(sumgreen / 6.000);
                int newblue = round(sumblue / 6.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;
            }

            //bottom left corner
            if (i == height - 1 && j == 0)
            {
                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;

                //loop for the sum for the average
                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = j; l <= j + 1; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                int newred = round(sumred / 4.000);
                int newgreen = round(sumgreen / 4.000);
                int newblue = round(sumblue / 4.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;
            }

            //bottom edge
            if (j != width - 1 && j != 0 &&  i == height - 1)
            {
                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;

                //loop for the sum for the average
                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                int newred = round(sumred / 6.000);
                int newgreen = round(sumgreen / 6.000);
                int newblue = round(sumblue / 6.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;
            }


            //bottom right corner
            if (i == height - 1 && j == width - 1)
            {
                int sumred = 0;
                int sumblue = 0;
                int sumgreen = 0;

                //loop for the sum for the average
                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                        sumred += image[k][l].rgbtRed;
                        sumgreen += image[k][l].rgbtGreen;
                        sumblue += image[k][l].rgbtBlue;
                    }
                }

                int newred = round(sumred / 4.000);
                int newgreen = round(sumgreen / 4.000);
                int newblue = round(sumblue / 4.000);

                //saving value in array copy
                copy[i][j].rgbtRed = newred;
                copy[i][j].rgbtGreen = newgreen;
                copy[i][j].rgbtBlue = newblue;
            }
        }
    }


    //transfering copy to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = copy[i][j];

        }
    }

    free(copy);

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    //definng the array to save the new value as we work on the main picture
    RGBTRIPLE(*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));


    //going over every pixel

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //defining gx and gy color values
            int redx = 0;
            int greenx = 0;
            int bluex = 0;
            int redy = 0;
            int greeny = 0;
            int bluey = 0;

            //go over the pixel with kernel matrix
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    //defining the kernels
                    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
                    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};


                    // checking if we are on an edges, so if we find a value smaller than 0 then the statement
                    // continue makes the loop ++ and don't read what's next.
                    // i.e if the pixel i = 0 and j = 0  then when we look at the kernel [0][0]
                    // 0 - 1 + 0 = -1 out of the picture --> continue
                    if (i - 1 + k < 0 || i - 1 + k > height - 1 || j - 1 + l > width - 1 || j - 1 + l < 0)
                    {
                        continue;
                    }

                    redx += image[i - 1 + k][j - 1 + l].rgbtRed * gx[k][l];
                    redy += image[i - 1 + k][j - 1 + l].rgbtRed * gy[k][l];
                    bluex += image[i - 1 + k][j - 1 + l].rgbtBlue * gx[k][l];
                    bluey += image[i - 1 + k][j - 1 + l].rgbtBlue * gy[k][l];
                    greenx += image[i - 1 + k][j - 1 + l].rgbtGreen * gx[k][l];
                    greeny += image[i - 1 + k][j - 1 + l] .rgbtGreen * gy[k][l];

                }//for loop column kernel
            }//for loop row kernel

            int red = round(sqrt((redx * redx) + (redy * redy)));
            int *r = &red;
            int blue = round(sqrt((bluex * bluex) + (bluey * bluey)));
            int *b = &blue;
            int green = round(sqrt((greenx * greenx) + (greeny * greeny)));
            int *g = &green;

            //dereferencing r if bigger than 255
            if (red > 255)
            {
                *r = 255;
            }

            if (blue > 255)
            {
                *b = 255;
            }

            if (green > 255)
            {
                *g = 255;
            }

            // saving the new value into the copy array
            copy[i][j].rgbtRed = red;
            copy[i][j].rgbtBlue = blue;
            copy[i][j].rgbtGreen = green;


        } //for loop column of image
    }//for loop row of image


    //copy the array copy over image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    free(copy);
    return;

}