/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 24/3/21
Description: Delineation Of Script Processing Records Of Fees Of A Track Club
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <stdio.h>                                          // Preprocessor Library
#include <ctype.h>                                          // Character Mapping Library
#include <string.h>                                         // String Library
int count = 1, tennis = 0, num, badminton = 0, swim = 0;    // Declaration Of Variables
float paid;
char name[100], code;
int main() {
    while (1) {                                              // Infinite While Loop
        printf("Enter Your Name or 0 To Exit\n");            // Prompt User For Name
        if (strcmp(name,"0") == 1){                          // Evaluate Exit Condition
            break;                                           // Exit Loop
        }
        scanf("%s", name);                                   // Read User Input As 'name'
        printf("Enter Amount Paid\n$");                      // Prompt User For Amount Paid
        scanf("%f", &paid);                                  // Read User Input As 'paid'
        while (1) {                                          // Infinite While Loop
            printf("Enter Code\n");                          // Prompt User For Code
            scanf(" %c", &code);                             // Read User Input As 'code'
            if (tolower(code) == 't') {                      // Evaluate If 'code' In All Common Is t
                printf("Name :%s\nSport : Tennis\nAmount Paid $%.2f\nBalance Remaining :$%.2f\n", name, paid, 18000-paid); //Display name','paid'&Balance
                tennis++;                                    // Increment 'tennis' By 1
                break;                                       // Exit Infinite Loop
            }
            if (tolower(code) == 'b') {                      // Evaluate If 'code' In All Common Is b
                printf("Name :%s\nSport : Badminton\nAmount Paid $%.2f\nBalance Remaining :$%.2f\n", name, paid, 14000-paid);
                badminton++;                                 // Increment 'badminton' By 1
                break;                                       // Exit Infinite Loop
            }
            if (tolower(code) == 's') {                      // Evaluate If 'code' In All Common Is s
                printf("Name :%s\nSport : Swimming\nAmount Paid $%.2f\nBalance Remaining :$%.2f\n", name, paid, 16000-paid);
                swim++;                                      // Increment 'swim' By 1
                break;                                       // Exit Infinite Loop
            }
            if (tolower(code) != 't' | tolower(code) != 'b' | tolower(code) != 's') {   //E valuate If code in All Common Is Neither t or b or s
                printf("Invalid\n");}
        }count++;                                            // Increment 'count' By 1
    }
    printf("Event       |  Total \nTennis\t\t%i\nBadminton\t%i\nSwimming\t%i\n",tennis,badminton,swim); // Display Events & Total
}