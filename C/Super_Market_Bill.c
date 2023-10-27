/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 4/2/21
Description: Delineation Of Script Prompting User For Total Bill And Calculating And Applying Loyalty Points
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
# include <stdio.h>
float bill,points;
int main(){
    printf("Enter Total Amount Due Then Enter Loyalty Points\n$");
    scanf("%f %f",&bill,&points);
    if (bill <= 5000.0){                   // Evaluates If 'bill' Is <= to 5000
    points += 6;                    // Increments Loyalty Points By 6
    if (points > 100){                // Evaluates If Loyalty Points > 99
    printf("Total Amount Due :$%.2f\nDiscount Amount :$%.0f\nBill Balance :$%.2f\nLoyalty Points : 0",bill,points,bill - points);  // outputs Totals
    points = 0;}                 // Initialize Loyalty Points to 0
    else{                          // Evaluates If Loyalty Points < 99
    printf("Total Amount Due :$%.2f\nLoyalty Points :%.0f",bill,points);}   // Outputs Totals Without Discount
    }
    if (5000.0 < bill && bill <= 15000.0){
        points += 10;
        if (points > 100){
            printf("Total Amount Due :$%.2f\nDiscount Amount :$%.0f\nBill Balance :$%.2f\nLoyalty Points : 0",bill,points,bill - points);
            points = 0;}
        else{
            printf("Total Amount Due :$%.2f\nLoyalty Points :%.0f",bill,points);}
    }
    if (bill > 15000.0){
        points += 15;
        if (points > 100){
            printf("Total Amount Due :$%.2f\nDiscount Amount :$%.0f\nBill Balance :$%.2f\nLoyalty Points : 0",bill,points,bill - points);
            points = 0;}
        else{
            printf("Total Amount Due :$%.2f\nLoyalty Points :%.0f",bill,points);}
    }
}