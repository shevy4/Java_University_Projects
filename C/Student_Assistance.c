/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Brown : 2001407
Date: 22/2/21
Description: Delineation Of Script Accepting Name, GPA And Tuition Then Displaying Eligibility Of Assistance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
# include <stdio.h>
char name[100];
float gpa, tuit;
int main(){
    printf("Enter Name, GPA Then Tuition Respectively\n");              // Prompt And Initialization Of 'name' 'gpa' And 'tuit'
    scanf ("%s %f %f",name,&gpa,&tuit);                               // Reading 'gpa' And 'tuit' As Float
    if (3.5 <= gpa && gpa <= 4.0){                                  // Evaluation Of Gpa
        printf("Name :%s\nAssistance Granted : Scholarship\nEligibility Amount :$%.2f",name,tuit*.8);}         // Output Of Eligibility
    if (3.0 <= gpa && gpa < 3.5) {
        if (tuit > 550000) {
            printf("Name :%s\nAssistance Granted : Grant\nEligibility Amount :$%.2f",name, tuit * .6);
        } else {
            printf("Name :%s\nAssistance Granted : Loan\nEligibility Amount :$%.2f",name, tuit * .6);
        }
    }
    if (2.7 <= gpa && gpa < 3.0){
        printf("Name :%s\nAssistance Granted : Textbook Voucher\nEligibility Amount :$%.2f",name,tuit * .1);}
    if (gpa < 2.7){
        printf("Name :%s\nAssistance Granted : None\nEligibility Amount :$%i",name,0);}
    return 0;
}
