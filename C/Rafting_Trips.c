/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Shaval Brown : 2001407
Date: 21/2/21
Description: Delineation Of Script Of Portland Rafting Trips Depicting bamboo raft trips & Cost
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include<stdio.h>                                  // Preprocessor Library
int main(){
    int count = 0 ,price = 0;                      // Initialize 'count' & 'price As 0
    char package, ID[15][100], name[15][100];      // Initialize 'ID' & 'name' As An Array 15x100 Of String
    while (count < 2){                             // While Loop Runs 15 Times Until 'count' = | > 15
        printf("\nEnter the customer's ID: ");     // Prompt User For Customer ID
        scanf("%s", &ID[count][0]);                // Read Input As 'ID' In Index 'count'
        printf("Enter the customer's name: ");     // Prompt User For Customer name
        scanf("%s", &name[count][0]);              // Read Input As 'name' In Index 'count'
        printf("1. Scenic Tour, US$119\n2. Relaxation Tour, US$139\n3. Joyous Fun Tour, US$159\n"); // Display Packages & Cost
        printf("\nEnter the package type number: ");  // Prompt User For Package Type As A Number As 'package'
        fflush(stdin);          // Clear Input Buffer
        scanf("%c", &package);  // Read Input As 'package'
        if (package == '1'){    // Evaluates If 'package' = '1'
            price += 119;}      // Increment 'price' By 119
        if (package == '2'){    // Evaluates If 'package' = '2'
            price += 139;}      // Increment 'price' By 139
        if (package == '3'){    // Evaluates If 'package' = '3'
            price += 149;}      // Increment 'price' By 149
        if (package != '1' && package != '2' && package != '3'){   // Evaluates If 'package' != '1', '2' | '3'
            printf("Invalid\n");}    // Output Invalid Choice
        count++;                    // Increment 'count'
    }
    printf("\nThe average cost per customer = US$%i\n", price/15);  // Display Average Cost Per Customer Rounded
    printf("The overall cost = US$%i", price);                      // Display Overall Cost Rounded
}
