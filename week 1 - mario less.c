#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    //mainloop
    do
    {
        n = get_int("Height of the pyramid btw 1 and 8 ?\n");
    }
    while (n < 1 || n > 8);
   
    
    // I need to set the patern of variable to print at each loop(see           below the code for thiking process)

    for (int i = 0; i < n ; i++)
    {
        int hash = (i + 1);
        int dots = (n - hash);

        //dotloop - first in order to have the pyramid on the right side
        
        for (int j = 0; j < dots ; j++)
        {
            printf(" ");  
        }
           
        

        //Hashloop - second as it the second think the computer has to             print in the line
        
        for (int j = 0 ; j < hash ; j++)
        {
            printf("#");   
        }
           
        //retour à la ligne en dehors des loops car les deux loops                 doivent se faire sur une ligne
        printf("\n");
    }
    
}
// Patern
//...x
//..xx
//.XXX
//XXXX
//n=4
//i=0 d=3 h=1
//i=1 d=2 h=2
//i=2 d=1 h=3
//i=3 d=0 h=4
// therefore the patern are: d = n-h
//                           h = n-d
// these paterns could not work because I need to define the patern with the variable that I defined in the loop (?)
// Hence the patern shoudl be definir with i and n:
// hash_counts = i + 1
// dots = n - hash_counts
