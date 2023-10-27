/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 22/2/21
Description: Delineation Of Script Managing Emergency Room Patients And Their Bill
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <stdio.h>
const int fee = 1500;                       // Declaration Of Constant
char id[100], name[100], pri, ref;          // Declaration Of 'id', 'name', As String, 'pri' And 'ref' as Char
int main(){
    printf("Enter Patient's Name\n");       // Prompt User For Patient's Name
    scanf("%[^\n]s",name);                  // Read User Input As 'name'
    printf("Enter Id Number Then Priority Level (1 Or 2)\n");  // Prompt User For ID Number And Priority Level
    scanf("%s %s",id, &pri);                        // Read User Input As 'id', 'pri'
    switch(pri){
        case '1': printf("Id #%s, %s Referred To Doctor On Duty @ Cost $1,500 + Standard Fee\nBill : $3,000",id,name);
                  return 0;
        case '2': printf("                                          _____\n"
                         "                                         [_____]\n"
                         "   N - Refer To Nurses Treatment Room     | o |\n"
                         "                                          |   |\n"
                         "   H - Refer To Health Centre            /   o \\\n"
                         "                                       / o       \\\n"
                         "   R - Refer To Regional Hospital    / __________o \\\n"
                         "                                   /      o         \\ \n"
                         "                                  <__________________>\n");
                    printf("Enter Referral Code\n");
                    scanf("%s",&ref);
                    switch (ref){
                        case 'N':
                        case 'n': printf("Id #%s, %s Referred To Nurses Treatment Room @ Cost $700 + Standard Fee\nBill : $2,200",id,name);
                                  return 0;
                        case 'H':
                        case 'h': printf("Id #%s, %s Referred To Health Centre @ Cost $100 + Standard Fee\nBill : $1,600",id,name);
                                  return 0;
                        case 'R':
                        case 'r': printf("Ambulance Service Required? Y/N : ");
                            ref = ' ';
                                  scanf("%s",&ref);
                                  switch (ref){
                                      case 'Y':
                                      case 'y': printf("Id #%s, %s Referred To Regional Hospital @ Cost $4,500 + Standard Fee\nBill : $6,000",id,name);
                                                return 0;
                                      case 'N':
                                      case 'n': printf("Id #%s, %s Referred To Regional Hospital @ Cost $500 + Standard Fee\nBill : $2,000",id,name);
                                                return 0;
                                      default:  printf("Invalid");
                                                return 0;}
                        default: printf("Invalid");
                                 return 0;}
        default: printf("Invalid");
                 return 0;
    }
}