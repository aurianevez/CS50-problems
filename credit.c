#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    long cc_nbr; // credit card number variable

    //asking for the cc_nbr
    cc_nbr = get_long("type your credit card number\n"); 
    
    if (cc_nbr < 3400000000000)
    {
        printf("INVALID\n");
    }
    if (cc_nbr > 5999999999999999)
    {
        printf("INVALID\n");
    }

    //promt for credit card number making sure that i get number btw 13 and 16 digit if under or higher print --> invalid

    //count the number of digit the cc_nbr has (need for the loop later)

    long nbr_digit = 0;
    long cc_nbr_fc = cc_nbr; 
    // I created a variable that has the same value than the cc_nbr so my cc_nbr does not  transforme into 0 value once i count the number of digit :
    do
    {
        nbr_digit = nbr_digit + 1;
        cc_nbr_fc = cc_nbr_fc / 10;
    }
    while (cc_nbr_fc != 0);
    

// I creat an array with the space for 16 values so i have a value for every digit of CC. 
//value for each digit starting from right to left - cc_digit [0] = first number on the right
// in the loop had to transforme the pow which returns in double into a long with long b = a 
   
    long cc_digit [16];
    for (long j = 0; j < 16 ; j++)
    {
        double a = pow(10, j);
        long b = a;
        cc_digit [j] = cc_nbr / b % 10;
    }
  
     
// variable created in order to add the products's digits together of luhn's algo. first part
    int b = 0;
    int d = 0;
    int f = 0;
    int h = 0;
    int j = 0;
    int l = 0;
    int n = 0;
    int p = 0;
    int digit_prod = 0;
    int final_add = 0;
    int last_digit = 0;

    // luhn's algorithm for credit card with 13 digit
    if (nbr_digit == 13)
    {
        b = cc_digit [1] * 2;
        d = cc_digit [3] * 2;
        f = cc_digit [5] * 2;
        h = cc_digit [7] * 2;
        j = cc_digit [9] * 2;
        l = cc_digit [11] * 2;
        

        if (b >= 10) 
        {
            b = b / 10 + b % 10;
        }
        
        if (d >= 10)
        {
            d = d / 10 + d % 10;
        }
        
        
        if (f >= 10) 
        {
            f = f / 10 + f % 10;
        }
        
        if (h >= 10) 
        {
            h = h / 10 + h % 10;
        }
        
        if (j >= 10) 
        {
            j = j / 10 + j % 10;
        }
        
        if (l >= 10)
        {
            l = l / 10 + l % 10;
        }
        
        // digit's products - last stage of 1st part of the luhn's aglo.
        digit_prod = b + d + f + h + j + l;
        // digit's products + the remaining number of the credit card
        final_add = digit_prod + cc_digit [0] + cc_digit [2] + cc_digit [4] + cc_digit [6] + cc_digit [8] + cc_digit [10] + cc_digit [12]; 

        //making sure that the sum of (digit*2) and remaining digit is equal to a number that ends with 0.     
        last_digit = final_add % 10;

        if (last_digit == 0 && cc_digit [12] == 4)
        {
            printf("VISA\n");
        }

        else if (last_digit != 0 || cc_digit [12] != 4)
        {
            printf("INVALID\n");
        }
        
    }

    // luhn's algorithm for credit card with 14 digit
    if (nbr_digit == 14)
    {
        b = cc_digit [1] * 2;
        d = cc_digit [3] * 2;
        f = cc_digit [5] * 2;
        h = cc_digit [7] * 2;
        j = cc_digit [9] * 2;
        l = cc_digit [11] * 2;
        n = cc_digit [13] * 2;
       
        if (b >= 10) 
        {
            b = b / 10 + b % 10;
        }

        if (d >= 10)
        {
            d = d / 10 + d % 10;
        }
        
        if (f >= 10) 
        {
            f = f / 10 + f % 10;
        }
        
        if (h >= 10) 
        {
            h = h / 10 + h % 10;
        }
       
        if (j >= 10) 
        {
            j = j / 10 + j % 10;
        }
       
        if (l >= 10)
        {
            l = l / 10 + l % 10;
        }
        if (n >= 10)
        {
            n =  n / 10 + n % 10;   
        }   
        
        // digit's products - last stage of 1st part of the luhn's aglo.
        digit_prod = b + d + f + h + j + l + n;
        final_add = digit_prod + cc_digit [0] + cc_digit [2] + cc_digit [4] + cc_digit [6] + cc_digit [8] + cc_digit [10] + cc_digit [12]; 
      
        last_digit = final_add % 10;
        

        if (last_digit == 0 && cc_digit [13] == 4)
        {
            printf("VISA\n");
        }

        else if (last_digit != 0 || cc_digit [13] != 4) 
        {
            printf("INVALID\n");
        }
    }
   
    // luhn's algorithm for credit card with 15 digit
    if (nbr_digit == 15)
    {
        b = cc_digit [1] * 2;
        d = cc_digit [3] * 2;
        f = cc_digit [5] * 2;
        h = cc_digit [7] * 2;
        j = cc_digit [9] * 2;
        l = cc_digit [11] * 2;
        n = cc_digit [13] * 2;
        

        if (b >= 10) 
        {
            b = b / 10 + b % 10;
        }

        if (d >= 10)
        {
            d = d / 10 + d % 10;
        }
        
        
        if (f >= 10) 
        {
            f = f / 10 + f % 10;
        }
        
        if (h >= 10) 
        {
            h =  h / 10 + h % 10;
        }
       
        if (j >= 10) 
        {
            j = j / 10 + j % 10;
        }
       
        if (l >= 10)
        {
            l = l / 10 + l % 10;
        }
        
        if (n >= 10)
        {
            n = n / 10 + n % 10;   
        }   

// digit's products - last stage of 1st part of the luhn's aglo.
        digit_prod = b + d + f + h + j + l + n; 

        final_add = digit_prod + cc_digit [0] + cc_digit [2] + cc_digit [4] + cc_digit [6] + cc_digit [8] + cc_digit [10] + cc_digit [12] +
                    cc_digit [14]; 

        last_digit = final_add % 10;
        
    
        if (last_digit == 0 && cc_digit [14] == 3 && cc_digit [13] == 4)
        {
            printf("AMEX\n");
        }

        else if (last_digit == 0 && cc_digit [14] == 3 && cc_digit [13] == 7)
        {
            printf("AMEX\n");
        }
        
        else if (last_digit != 0)
        {
            printf("INVALID\n");
        }

        else if (last_digit == 0 && cc_digit [14] == 3 && cc_digit [13] != 7)
        {
            printf("INVALID\n");
        }

        else if (last_digit == 0 && cc_digit [14] == 3 && cc_digit [13] != 4)
        {
            printf("INVALID\n");
        }
    
    }
    // luhn's algorithm for credit card with 16 digit
    if (nbr_digit == 16)
    {
        b = cc_digit [1] * 2;
        d = cc_digit [3] * 2;
        f = cc_digit [5] * 2;
        h = cc_digit [7] * 2;
        j = cc_digit [9] * 2;
        l = cc_digit [11] * 2;
        n = cc_digit [13] * 2;
        p = cc_digit [15] * 2;
       
        if (b >= 10) 
        {
            b = b / 10 + b % 10;
        }

        if (d >= 10)
        {
            d = d / 10 + d % 10;   
        }
        
        if (f >= 10) 
        {
            f = f / 10 + f % 10;
        }
        
        if (h >= 10) 
        {
            h = h / 10 + h % 10;
        }
       
        if (j >= 10) 
        {
            j = j / 10 + j % 10;  
        }
       
        if (l >= 10)
        {
            l = l / 10 + l % 10;
        }

        if (n >= 10)
        {
            n = n / 10 + n % 10;   
        }  

        if (p >= 10)
        {
            p = p / 10 + p % 10;    
        }
       
// digit's products - last stage of 1st part of the luhn's aglo.
        
        {
            digit_prod = b + d + f + h + j + l + n + p;

            final_add = digit_prod + cc_digit [0] + cc_digit [2] + cc_digit [4] + cc_digit [6] + cc_digit [8] + cc_digit [10] + cc_digit [12] +
                        cc_digit [14]; 
       
            last_digit = final_add % 10;
            
        }

        if (last_digit == 0 && cc_digit [15] == 4)
        {
            printf("VISA\n");
        }
        
        else if (last_digit == 0 && cc_digit [15] == 5 && cc_digit [14] <= 5)
        {
            printf("MASTERCARD\n");
        }

        else if (last_digit == 0 && cc_digit [15] == 5 && cc_digit [14] > 5)
        {
            printf("INVALID\n");
        }

        else if (last_digit != 0) 
        {
            printf("INVALID\n");
        }
        
        else  if (cc_digit [15] != 5 && cc_digit [15] != 4) 
        {
            printf("INVALID\n");
        }
        
    }
 
}

// patern for the loop for the cc_digit [] array
// first_digit = cc_nbr/1 % 10;
//second_digit = cc_nbr / 10 % 10; 
//third_digit = cc_nbr / 100 % 10;
// j = 0 ; div = 1
// J = 1 ; div = 10 = 10^j
// j = 2 ; div = 100 
// 10^j
        



