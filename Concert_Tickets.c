/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 4/2/21
Description: Delineation Of Script Accepting Ticket Type And Number Of Persons, And Displaying Costs And Totals
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
# include <stdio.h>                                                             //Preprocessor I/O Library
# include <string.h>                                                          // String Library To Use String Compare
int num, tic1 ,tic2, tot1, tot2 = 0;                                        // Initializing Of Variables For Total Students And Total Cost Etc
char tic [100];                                                           // Initializing Of Variable For Ticket Type
int main(){
    while (1){                                                        // Infinite Loop
        printf("Enter Ticket Type: 'R' Or 'G' Or Exit To Print Receipt\n");                       // Prompt User To Choose Type Of Ticket Or Print Receipt
        scanf("%s",tic);                                                                         // Read Choice As 'tic'
        if (strcmp(tic, "Exit") == 0 | strcmp(tic, "exit") == 0) {                             // Compares 'tic' To Exit Or exit
            break;                                                                           // Breaks Infinite Loop
        }
        printf("Enter Number Of Students\n");                                             // Prompts User For Number Of Students
        scanf("%i",&num);                                                               // Reads Number Of Students As 'num'
        if (tic[0] == 'r' | tic[0] == 'R'){                                           // Indexes tic And Evaluates If The 1st Index Is R or r
            tic1 += num * 6500;                                                     // Increments ticket Amount Total
            tot1 += num;                                                          // Increments Total Ticket Type
        }
        else if (tic[0] == 'g' | tic[0] == 'G'){                               // Indexes tic And Evaluates If The 1st Index Is G or g If Prior Condition False
            tic2 += num * 7500;                                              // Increments ticket Amount Total
            tot2 += num;                                                   // Increments Total Ticket Type
        }else{                                                           // Evaluates If All Prior Conditions Are False
            printf("Invalid\n");                                       // Outputs Invalid If All Prior Conditions Are False
        }
    }
     // prints the
    printf("Ticket Type : \t\t\t Students\nGeneral : $%i\t\tStudents :%i\nReserved :"
           " $%i\t\tstudents :%i\n\t\tTotal Cost :"
           " $%i",tic2,tot1,tic1,tot2,tic1 + tic2);        // Outputs Total Student Per Ticket And Total Ticket Costs
    return 0;
}