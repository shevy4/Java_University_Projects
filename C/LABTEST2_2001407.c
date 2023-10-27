/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 24/3/21
Description: Delineation Of Pseudocode Converted To C
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
# include <stdio.h>  //Preprocessor Library
int custID, cust_cnt = 0 , pack_weight = 0, ship_code = 0;    //Declaration Of Variables
float duty_tax = 0.0, total_tax = 0.0, ship_rate = 0.0, ship_cost = 0.0, revenue = 0.0, total_cost = 0.0;
int main(){
    printf("-----------------------------------------------\n\tWELCOME TO MYRIE'S SHIPPING\n-----------------------------------------------\n");
    printf("Enter Customer ID or 0 To Exit\n");
    scanf("%i", &custID);                                        // Accept Customer ID As "custID'
    while (custID != 0){                                         // While Loop With Condition "custID' != 0
        duty_tax, ship_cost, total_cost = 0;
        do {                                                     // Initiate Do-while Loop
            printf("Enter Package Weight > 0 Kg\n");             // Output To Screen
            scanf("%i", &pack_weight);                           // Input Package Weight as "pack_weight'
        } while (pack_weight <= 0);                              // While Loop With Condition "pack_weight" < or = 0
        do {                                                     // Initiate Do-while Loop

            printf("\t\t\t\tEnter Code :\n[1] - 5 days USD 4.25 Per Kg\n[2] - 3 Days USD 5 weight >= 25kg or USD 3.75 Per Kg\n"
                   "[3] - Priority Shipping  USD 7.00 Per Kg\n");
            scanf("%i", &ship_code);                             // Accept Shipping Code As 'ship_code"
            swit:                                                // Goto label To Resume From
            switch (ship_code){                                  // Initiate Switch Statement of 'ship_code"
                case 1: ship_rate = 4.25;                        // Case Condition '1'
                        ship_cost = pack_weight * ship_rate;
                        duty_tax = ship_cost * .20;
                        total_cost = ship_cost + duty_tax;
                        total_tax += duty_tax;
                        revenue += total_cost;
                        printf("Shipping Details: 5 Days Shipping\n");
                        break;                                  // Exit Case Condition

                case 2: if (pack_weight >= 25){                // Case Condition '2', Evaluate If 'pack_weight >= 25
                        ship_rate = 5;
                        ship_cost = pack_weight * ship_rate;
                        duty_tax = ship_cost * .20;
                        total_cost = ship_cost + duty_tax;
                        total_tax += duty_tax;
                        revenue += total_cost;}
                        else{                                     // Inverse Evaluate 'pack_weight'
                        ship_rate = 3.75;
                        ship_cost = pack_weight * ship_rate;
                        duty_tax = ship_cost * .20;
                        total_cost = ship_cost + duty_tax;
                        total_tax += duty_tax;
                        revenue += total_cost;}
                        printf("Shipping Details: 3 Days Shipping:");
                        break;                                   // Exit Case Condition

                case 3: ship_rate = 7;                          // Case Condition '1'
                        ship_cost = pack_weight * ship_rate;
                        duty_tax = ship_cost * .20;
                        total_cost = ship_cost + duty_tax;
                        total_tax += duty_tax;
                        revenue += total_cost;
                        printf("Shipping Details: Priority Shipping\n");
                        break;                                  // Exit Case Condition

                default: printf("Invalid Code\n");
                         printf("\t\t\t\tEnter Code :\n[1] - 5 days USD 4.25 Per Kg\n[2] - 3 Days USD 5 weight >= 25kg or USD 3.75 Per Kg\n"
                           "[3] - Priority Shipping  USD 7.00 Per Kg\n");
                         scanf("%i", &ship_code);               // Accept Shipping Code As 'ship_code'
                         goto swit;                             // Goto Label 'swit' And Proceed With Code Imitating A Loop
                         // break;
            }
            printf("Customer ID: %i\n",custID);                 // Output Customer ID
            printf("Ship Rate Per Kg: %.2f\n", ship_rate);      // Output Shipping Rate
            printf("Shipping Cost: $%.2f\n", ship_cost);        // Output Shipping Cost
            printf("Duty Tax: $%.2f\n", duty_tax);              // Output Total Duty Tax
            printf("Total Amount Due: $%.2f\n", total_cost);    // Output Total Amount Due
        } while (ship_code <= 0 | ship_code > 3);               // While Loop With Condition 'ship_code" <= 0 or > 3
        cust_cnt ++;                                            // Increment 'cust_cnt' by 1
        printf("Enter Customer ID or 0 To Exit\n");             // Output To Screen
        scanf("%i", &custID);                                   // Accept Customer ID as 'custID'
    }
    printf("Total Customers: %i\n", cust_cnt);                  // Output Total Customer
    printf("Total Duty Tax Received: $%.2f\n", total_tax);      // Output Total Duty Tax
    printf("Total Revenue Earned: $%.2f\n", revenue);           // Output Total Revenue
}
