/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001
Date: 21/2/21
Description: Delineation Of Script Simulating An ATM Transaction With A Customer
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
# include <stdio.h>
int cho;                                          // Initializes cho as integer
float cash;                                      // Initializes Cash as float
int main(){
    do {
    printf("/ ,-----------------. \\\n"
           "| |Select ::: Choice| |\n"
           "| `-----------------' |\n"
           "| [1] Check Balance   |\n"
           "|              ###### |\n"
           "| [2] Deposit         |\n"
           "| $$$$$$$             |\n"
           "| [3] Withdrawal      |\n"
           "\\____________________/");
    printf("\nEnter Choice 1-3\n");                  // Prompts User For Transaction Intended
    scanf("%i",&cho);}                               // Reads Transaction Intended as 'cho'
    while(cho != 1 && cho != 2 && cho != 3);
    switch(cho) {                                   // Switch Statement
        case 1: printf("Balance : $30000");         // Evaluate If 'cho' == 1, Balance Displayed
            break;                                  // Exit Switch
        case 2: while (1) {                         // Evaluate If 'cho' == 2
                printf("Enter Deposit Amount < $100,001\n$");     // Prompts User For Deposit Amount
                scanf("%f", &cash);                               // Reads Deposit As 'cash'
                if (cash<0){                                      // Evaluates If Cash Is Negative
                    printf("Error\n");                            // Displays Error
                    return 0;}                                    // Exits Code
                if (cash > 100000) {                              // Evaluates If Cash Exceeds 100k
                    printf("Deposit Exceed $100,000\n");          // Displays Amount Exceeded
                } else {
                    printf("Deposit Successful\nBalance :$%.2f", 30000+cash);   // Displays Balance
                    return 0;}                                    // Exits Code
            }
        case 3: while (1) {                                       // Evaluate If 'cho' == 3
                printf("Enter Withdrawal Amount\n$");
                scanf("%f", &cash);
                if (cash<0){
                    printf("Error\n");
                    return 0;}
                if (cash > 17000) {
                    printf("Withdrawal Exceeded $17,000\n");}
                else{
                    printf("Withdrawal Successful\nBalance :$%.2f",30000-cash);
                    return 0;}
            }
        default: printf("Invalid\n");
    }}