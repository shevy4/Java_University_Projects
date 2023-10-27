/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 24/2/21
Description: Delineation Of Script Calculating BMI
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <stdio.h>                                                         // Preprocessor Library
float bmi, weight, height;                                               // Initializes 'bmi', 'weight' and 'height' As Float
int main(){                                                            // Main Function
    printf("Enter Your Weight (Kg), Then Enter Your Height (Cm)\n"); // Prompt To User To Enter Weight Then Height
    scanf("%f %f",&weight, &height);                               // Reads 'weight' And 'height'
    bmi = weight/((height/100)*(height/100));                    // Calculates 'bmi'
    if (bmi <= 18.5){                                          // Evaluates bmi Less than Or Equal To 18.5
        printf("You Are Under Weight\n");}
    else if (bmi > 18.5 && bmi < 25){                      // Evaluates bmi Between 18.5 And 25
        printf("Your Weight Is Normal\n");}
    else if (bmi >= 25 && bmi <= 35){                  // Evaluates bmi Between 25 And 35 Inclusive
        printf("You Are Over Weight\n");}
    else{
        printf("You Are Obese\n");}             // Outputs To Screen If No Condition Is Met
}