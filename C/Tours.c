/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Brown : 2001407
    Date:
    Description: Displaying the user's name, ID number and their overall total for the specific package they chose for the rafting trip.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                   */
#include <stdio.h>
#include <unistd.h>
int main ()
{
    
    int duration, package,scenic_tour, relaxation_tour, joyous_fun_tour, total; //Reserves six spaces in RAM called duration, package, scenic_tour, relaxation_tour, joyous_fun_tour and total to store data of type integer.
    char name [20]; //Reserves a space in RAM called name to store data of type string.
    char cid [10]; //Reserves a spaces in RAM called cid to store data of type string.
    scenic_tour = 119; //The value of 119 is assigned to the variable called scenic_tour
    relaxation_tour = 139; //The value of 139 is assigned to the variable called relaxation_tour
    joyous_fun_tour = 149; //The value of 149 is assigned to the variable called joyous_fun_tour
    printf ("Please enter your fullname:"); //Prompts the user to enter their first name.
    scanf("%[^\n]s", name); //Takes the value entered at the keyboard by the user and stores it at the location called name
    printf("Please enter your ID number:"); //Prompts the user to enter their ID number.
    scanf ("%s", cid); //Takes the value entered at the keyboard by the user and stores it at the location called cid
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n|\t\tWelcome %s \t\t|\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n","Bob The Builder");
    printf("Package costs are:\n");
    sleep(5);

    printf(".........................................................\n");
    printf ("1) Scenic Tour USD119\n2) Relaxation Tour USD139\n3) Joyous Fun Tour USD149\n"); //Displays the content of the different packages and their costs on the screen to the user
    printf(".........................................................\n");
    printf ("Which package would you like to purchase (1, 2 or 3)?\n"); //Prompts the user to enter which package they would like to choose
    scanf ("%d", &package); //Takes the value entered at the keyboard by the user and stores it at the location called package
    printf ("Would you like to spend 1, 2 or 3 hours?\n"); //Prompts the user to enter if they would like to spend 1, 2 or 3 hours on the trip
    scanf ("%d", &duration); //Takes the value entered at the keyboard by the user and stores it at the location called duration
    if (package == 1)  //Compares the content of the memory location scenic_tour to see if what is stored there is the same as what the user has chosen
    {
        total = scenic_tour + (duration * 20); //Multiplies the content of the variable duration by 20 then adds that sum to the content of the variable scenic_tour 
        printf ("%s,", name ); //Displays the contents of the variable name on the screen to the user
        printf (" %s,", cid ); //Displays the contents of the variable cid beside of the variable name on the screen to the user
        printf (" Your total is:$%d", total); //Displays the contents of the variable total in the same line as the name and  cid on the screen to the user
    }
    else
    {
        if (package == 2) //Compares the content of the memory location relaxation_tour to see if what is stored there is the same as what the user has chosen
        {
            total = relaxation_tour + (duration * 20); //Multiplies the content of the variable duration by 20 then adds that sum to the content of the variable relaxation _tour 
            printf ("%s,", name ); //Displays the contents of the variable name on the screen to the user
            printf (" %s,", cid ); //Displays the contents of the variable cid beside of the variable name on the screen to the user
            printf (" Your total is:$%d", total); //Displays the contents of the variable total in the same line as the name and  cid on the screen to the user
        }
        else
        {
            if (package == 3) //Compares the content of the memory location joyous_fun_tour to see if what is stored there is the same as what the user has chosen
            {
                total = joyous_fun_tour + (duration * 20); //Multiplies the content of the variable duration by 20 then adds that sum to the content of the variable joyous_fun _tour 
                printf ("%s,", name ); //Displays the contents of the variable name on the screen to the user
                printf (" %s,", cid ); //Displays the contents of the variable cid beside of the variable name on the screen to the user
                printf (" Your total is:$%d", total); //Displays the contents of the variable total in the same line as the name and  cid on the screen to the user
            }
        }
    }
}








