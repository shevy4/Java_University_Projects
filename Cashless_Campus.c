#include <stdio.h>
#include <unistd.h>

int main() {
    int b;
    while (1) {
        float amount[5];
        float a;
        printf("        ,--------------------------,             ,___________ \n"
               "       ,                         , |         ,/            /'| \n"
               "      +--------------------------+ |      ,/            /'    | \n"
               "     |  .--------------------.  |  |     +---------+ '        | \n"
               "     |  |     :::Pay:::      |  |  |     | -==----'|          | \n"
               "     |  | (0)Exit            |  |  |     |         |          |  \n"
               "     |  | (1)School Fees     |  |  |     |         |          | \n"
               "     |  | (2)Boarding Fees   |  |  |/----|`---=    |         ,|\n"
               "     |  | (3)Library Fees    |  |  |   ,/|==== ooo |        /;\n"
               "     |  | (4)Topup LunchCard |  |  |  // |(((( [33]|      /,\n"
               "     |  `--------------------'  |,_.;' | |((((     |  , / \n"
               "     +--------------------------+  ;;  | |         |, / \n"
               "        /_)_________________(_/  //'   | +---------+\n"
               "   _____________________________/___  `,\n"
               "  /  oo ENTER A CHOICE .o.  oooo /,   \\,\"-----------\n"
               " / =oo FROM 1 - 4 oo==.o.  ooo= //   ,`\\--{)B     ,\"\n"
               "/_==__==========__==_ooo__ooo=_/'   /___________,\"");
        printf("\n\nEnter 0 To Exit Or Enter Choice : \n");
        scanf(" %i", &b);

        switch (b) {
            case 0:
                return 0;
            case 1:
                for (int x = 0; x < 5; x++) {
                    printf("Enter 0 To Exit Or Enter School Fee\n$");
                    scanf("%f", &amount[x]);
                    if (amount[x] == 0) {
                        break;
                    }
                    if (amount[x] < 100000) {
                        printf("Balance is $%.2f\nReceipt # 00%i\n", (amount[x] * .15) + amount[x], x + 1);
                    } else {
                        printf("Balance is $%.2f\nReceipt # 00%i\n", amount[x], x + 1);
                    }
                    if (x % 2 == 0) {
                        printf("Litter Duty On : Tuesdays And Thursdays\n");
                    } else {
                        printf("Litter Duty On : Monday And Wednesday\n");
                        }
                }
                printf("loading...\n");
                sleep(2);
                break;
            case 2:
            start:
                for (int x=0;x<5;x++) {
                    int c;
                    printf("Enter 0 To Exit Or Enter Boarding Fees\n$");
                    scanf("%f", &amount[x]);
                    if (amount[x] == 0) {
                        break;
                    }
                    printf("Enter 0 To Exit Or Enter Boarding Location\n");
                    printf("  .=====================.        \n"
                           "   | (1)Wedderburn Hall |        \n"
                           "   | (2) Val Hal        |        \n"
                           "   | (3)  T Hall        |        \n"
                           "   |____________________|        \n"
                           "   |__________________-_|_,-.    \n"
                           "  [______________________]  )   \n"
                           "  .,,,,,,,,,,,,,,,,,, ,,/   (_   \n"
                           " /,,,,,,,,,,,,,,,,,, ,,/   (>`\\ \n"
                           "(________.-``-._______)     \\__)\n");
                    printf("Enter Choice : ");
                    scanf("%i", &c);
                    switch (c) {
                        case 1:
                            if ((amount[x] - 2500) <= 0) {
                                printf("Remaining Balance $%.2f\nFees Paid\n", amount[x] - 2500);
                            } else {
                                printf("Remaining Balance $%.2f\nFees UnPaid\n", amount[x] - 2500);
                            }
                            break;
                        case 2:
                            if ((amount[x] - 5000) <= 0) {
                                printf("Remaining Balance $%.2f\nFees Paid\n", amount[x] - 5000);
                            } else {
                                printf("Remaining Balance $%.2f\nFees UnPaid\n", amount[x] - 5000);
                            }
                            break;
                        case 3:
                            if ((amount[x] - 6000) <= 0) {
                                printf("Remaining Balance $%.2f\nFees Paid\n", amount[x] - 6000);
                            } else {
                                printf("Remaining Balance $%.2f\nFees UnPaid\n", amount[x] - 6000);
                            }
                            break;
                        default:
                            printf("invalid...\n");
                            goto start;
                    }
                }
                printf("Loading...\n");
                sleep(2);
                break;
            case 3:
                a = 0;
                for (int x = 0;x<5;x++){
                    printf("Enter 0 To Exit Or Library Fees\n$");
                    scanf("%f",&amount[x]);
                    if (amount[x] == 0){
                        break;
                    }
                    if (amount[x] > a){
                        a = amount[x];
                    }
                }
                printf("Highest Library Fee :$%.2f\nLoading...",a);
                sleep(2);
                break;
            case 4:
                   for (int x=0;x<5;x++) {
                       int c;
                       start2:
                       printf("Enter 0 To Exit Or Enter Top Up Amount\n$");
                       scanf("%f",&amount[x]);
                       if (amount[x] == 0){
                           break;
                       }
                       printf("  .=====================.        \n"
                              "   |  ::Select Status:: |        \n"
                              "   | (1)Student Body    |        \n"
                              "   | (2)Student Athlete |        \n"
                              "   | (3)Neither         |        \n"
                              "   |____________________|        \n"
                              "   |__________________-_|_,-.    \n"
                              "  [______________________]  )   \n"
                              "  .,,,,,,,,,,,,,,,,,, ,,/   (_   \n"
                              " /,,,,,,,,,,,,,,,,,, ,,/   (>`\\ \n"
                              "(________.-``-._______)     \\__)\n");
                       printf("Enter Choice : ");
                       scanf("%i",&c);
                       switch(c){
                           case 1:printf("Successfully Topped Up $%2.f On Card\n",amount[x] + 2000);
                               break;
                           case 2:printf("Successfully Topped Up $%2.f On Card\n",amount[x] + 3000);
                               break;
                           case 3:printf("Successfully Topped Up $%2.f On Card\n",amount[x]);
                               break;
                           default:printf("Invalid...");
                               goto start2;
                       }
                            }
                printf("Loading...");
                sleep(2);
                        break;
             default:
                     printf("Invalid\n");
                     sleep(2);
                     break;
        }
    }
}