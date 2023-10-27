/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Shaval Brown : 2001407
Date: 4/8/21
Description: Delineation Of Script Accepting 50 Students Data And Total Tuition
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
# include <stdio.h>
# include <ctype.h>
char status[50];
int ID[50], board = 0, trav = 0;
float Tuit[50], totaltuit=0;
int main(){
    for (int count = 0; count < 50; count++) {
        printf("Enter Student ID Number Or 0 To Exit\n");
        scanf("%i", &ID[count]);
        if (ID[count] == 0){
            break;}
        printf("Enter Tuition\n");
        scanf("%f", &Tuit[count]);
        totaltuit += Tuit[count];
        start:
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\tEnter Character\n\t(B) - Boarding\t\t(T) - Traveling\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");fflush(stdin);
        scanf("%c", &status[count]);
        switch (tolower(status[count])){
            case 'b':
                board++;break;
            case 't':
                trav++;break;
            default:
                printf("Invalid\n");
                goto start;}  }
    printf("Total Students = %i\nBoarding Students = %i\nTraveling Students = %i\n", board+trav,board,trav);
    printf("Total Tuition = $%.2f",totaltuit);}