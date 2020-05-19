#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])

{

    typedef uint8_t BYTE;

    //accepting only one commande line argument

    if (argc != 2)
    {
        printf("Usage: ./recover name of the forensic image file\n");
        return 1;
    }


    // I can open the file with argv[1] as the name of the file will be the only argument and the first
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("could not open file");
        return 2;
    }

    //counter for name of the jpeg file
    int count = 0;

    //buffer to store the information
    BYTE buffer[512];

    //array for the name of the JPEG
    char filename[9];

    //file were the jpeg will be store
    FILE *img = NULL;




    while (fread(buffer, 512, 1, file))
    {
        //begining of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if first Jpeg found
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                count++;
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
            }

            //if jpeg already found - first close previous jpeg file then open a new one
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", count);
                count++;
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
            }

        }

        //keep writing the Jpeg info
        else if (img != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, img);
        }

    }

    fclose(img);
    fclose(file);

}



