#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main() {
    char name[21];
    int id_num, pri;
    float bill;
    char code;


    printf("Please enter your name:\n ");
    fgets(name, 21, stdin);
    fflush(stdout);

    printf("What is your ID Number:\n");
    scanf("%d", &id_num);

    printf("What is your bill amount:\n");
    scanf("%f", &bill);

    printf("Is the patient a level 1 or level 2 priority:\n ");
    scanf("%d", &pri);
    codee:
    sleep(1);

    printf("\t\n"
           "     ____________________________\n"
           "    !\\_________________________/!\\\n"
           "    !! Referral Code |  Cost   !! \\\n"
           "    !!      D          $1,500  !!  \\\n"
           "    !!                         !!  !\n"
           "    !!      N          $700    !!  !\n"
           "    !!                         !!  !\n"
           "    !!      H          $100    !!  !\n"
           "    !!                         !!  !\n"
           "    !!      R          $500    !!  /\n"
           "    !!_________________________!! /\n"
           "    !/_________________________\\!/\n"
           "       __\\_________________/__/!_\n"
           "      !_______________________!/\n"
           "    ________________________\n"
           "   /oooo  oooo  oooo  oooo /!\n"
           "  /ooooooooooooooooooooooo/ /\n"
           " /ooooooooooooooooooooooo/ /\n"
           "/_______________________/_/\n");

    scanf("%c", &code);

    if (pri == 1) {
        printf("Patient is referred to the doctor on duty with a cost referral cost of $1500\n");

    }
    if (pri == 2) {
        printf("Enter the referral code:\n");
        scanf("%c", &code);
        code = tolower(code);
    }

    switch (code) {
        case 'r':
            printf("Would You Like Ambulance Service $4500? Y/N?\n");
            scanf("%s", &code);
            if (tolower(code) == 'y') {
                printf("Ambulance Service Received\n");
                break;
            }
            printf("No Ambulance");
            break;
        case 'n':
            printf("You Are Scheduled For Nurse Treatment $700");
            break;
        default:
            printf("ばか");
            goto codee;
    }
}
