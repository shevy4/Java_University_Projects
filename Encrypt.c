/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 5/2/21
Description: Delineation Of Script Accepting The Weight, Height And Shoe Size And Returns The Description
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
# include <stdio.h>                                                //Preprocessor I/O Library
int num;                                                         // Declares 'num' As Integer
int main(){
    printf("Enter A 4 Digit Num\n");                         // Prompts User To Enter A 4 Digit Number
    scanf("%i",&num);                                      // Reads Number As 'num'
    if (num / 1000 < 5){                                 // Evaluates If 1st Digit Is Less Than 5
        printf("%i ",num / 1000);                      // Outputs The 1st Digit If True
    }else{                                           // Evaluates If Condition Is False
        printf("%i ",9 - num / 1000);              // Outputs The Difference Of The 1st Digit And 9 If False
    }
    if (((num / 100) % 10) < 5){
        printf("%i ",(num / 100) %10);
    }else{
        printf("%i ",9 - (num / 100) %10);
    }
    if (((num / 10) % 10) < 5){
        printf("%i ",(num / 10) %10);
    }else{
        printf("%i ",9 - (num / 10) %10);
    }
    if (num % 10 < 5){
        printf("%i ",num % 10);
    }else{
        printf("%i ",9 - (num %10));
    }
    return 0;                                    // Returns exit code NIL
}