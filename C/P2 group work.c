#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Child
{
    char childFname[50];
    char childLname[50];
    char childId[15];
    char childGender[10];
    char childAddress[100];
    char childDob[15];
    char childPid[100];
    char childSassignment[100];

} Child;

typedef struct Parent
{
    char parentFname[50];
    char parentLname[50];
    char guardianId[15];
    char parentRelationship[10];
    char parentAddress[100];
    char parentTno[15];
    char parentEmail[40];
} Parent;

typedef struct Caregiver
{
    char caregiverFname[50];
    char caregiverLname[50];
    char caregiverId[15];
    char caregiverGender[10];
    char caregiverAddress[100];
    char caregiverArange[100];
    char caregiverSassignment[15];

} Caregiver;




void childInfo();
void parentInfo();
void caregiverInfo();



void createchildAccount();
void createcaregiverAccount();
void createparentAccount();

void displaychildInfo();
void displaycaregiverInfo();
void displayparentInfo();

void updatechildInfo();
void updatecaregiverInfo();
void updateparentInfo();

void listparentnchild();

void deletechildInfo();
void deletecaregiverInfo();
void deleteparentInfo();

void searchchildInfo();
void searchcaregiverInfo();
void searchparentInfo();

void listcaregiverInfo();

//=====================================================Main Menu=================================================================
int main()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\t\t====== Child Management Database System ======\n");
        printf("\n\t\t\t1. Child Account");
        printf("\n\t\t\t2. Parent/Guardian Information");
        printf("\n\t\t\t3. Caregiver Information");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            childInfo();
            break;
        case '2':
            parentInfo();
            break;
        case '3':
           caregiverInfo();
            break;
        case '0':
            printf("\n\t\t\t====== Thank You ======");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
    return 0;
}

//==========================================================Prgram for Child Account=======================================================

void childInfo()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\t\t====== Child Management Database System ======\n");
        printf("\n\t\t\t1. Create child Account");
        printf("\n\t\t\t2. Display All child Information");
        printf("\n\t\t\t3. Update child Information");
        printf("\n\t\t\t4. Delete child Information");
        printf("\n\t\t\t5. Search child Information");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            createchildAccount();
            break;
        case '2':
            displaychildInfo();
            break;
        case '3':
            updatechildInfo();
            break;
        case '4':
            deletechildInfo();
            break;
        case '5':
            searchchildInfo();
            break;
        case '0':
            printf("\n\t\t\t====== Thank You ======");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }

}

void createchildAccount()
{
    FILE *fileOne = fopen("childInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Child childInformation;

    system("cls");

    printf("\t\t\t====== Create child Account ======\n");

    printf("\n\t\t\tEnter child's First Name : ");
    getchar();
    gets(childInformation.childFname);

    printf("\n\t\t\tEnter child's Last Name : ");
    getchar();
    gets(childInformation.childLname);
    printf("\n\t\t\tEnter child's ID : ");
    gets(childInformation.childId);
    printf("\n\t\t\tEnter child's gender : ");
    gets(childInformation.childGender);
    printf("\n\t\t\tEnter child's Address : ");
    gets(childInformation.childAddress);
    printf("\n\t\t\tEnter child's date of birth : ");
    gets(childInformation.childDob);
    printf("\n\t\t\tEnter Parent's ID : ");
    gets(childInformation.childPid);
    printf("\n\t\t\tEnter child's section Assignment : ");
    gets(childInformation.childSassignment);


    fwrite(&childInformation, sizeof(childInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void displaychildInfo()
{
    FILE *fileOne = fopen("childInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Child childInformation;

    system("cls");

    printf("\t\t\t\t====== All children Information ======\n");

    printf("\n\n\t\t%-25s%-15s%-10s%-7s%-20s%-15s%-7s%-s\n", "First Name","Last Name", "ID","Gender", "Address", "DOB", "Section Assignment");
    printf("\t\t--------------------------------------------------------------------------------------------------------------------------------------------------");

    while (fread(&childInformation, sizeof(childInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-25s%-15s%-10s%-7s%-20s%-15s%-7s%", childInformation.childFname, childInformation.childLname, childInformation.childId, childInformation.childGender,childInformation.childAddress, childInformation.childDob,childInformation.childSassignment);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}


void updatechildInfo()
{
    FILE *fileOne = fopen("ChildInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Child childInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Update Kids Information ======\n");

    printf("\n\t\t\tEnter Child's ID : ");
    getchar();
    gets(tempInformation.childId);

    while (fread(&childInformation, sizeof(childInformation), 1, fileOne) == 1)
    {
        if (strcmp(childInformation.childId, tempInformation.childId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update child's first Name\n\t\t\t2.Update child's last Name\n\t\t\t3.Update child ID\n\t\t\t4.Update child Address\n\t\t\t5.Update Child Section Assignment");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter First's Name to Update: ");
                getchar();
                gets(tempInformation.childFname);
                strcpy(childInformation.childFname, tempInformation.childFname);

                fwrite(&childInformation, sizeof(childInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter child's Last Name to Update: ");
                getchar();
                gets(tempInformation.childLname);
                strcpy(childInformation.childLname, tempInformation.childLname);

                fwrite(&childInformation, sizeof(childInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter child's ID to Update: ");
                getchar();
                gets(tempInformation.childId);
                strcpy(childInformation.childId, tempInformation.childId);

                fwrite(&childInformation, sizeof(childInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter  child's Address to Update: ");
                getchar();
                gets(tempInformation.childAddress);
                strcpy(childInformation.childAddress, tempInformation.childAddress);

                fwrite(&childInformation, sizeof(childInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter child's section assignment to Update: ");
                getchar();
                gets(tempInformation.childSassignment);
                strcpy(childInformation.childSassignment, tempInformation.childSassignment);


                fwrite(&childInformation, sizeof(childInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&childInformation, sizeof(childInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&childInformation, sizeof(childInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("childInfo.bin");
    rename("temp.bin", "childInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tNo info");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void deletechildInfo()
{
    FILE *fileOne = fopen("childInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Child childInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Delete Student Information ======\n");

    printf("\n\t\t\tEnter child's ID : ");
    getchar();
    gets(tempInformation.childId);

    while (fread(&childInformation, sizeof(childInformation), 1, fileOne) == 1)
    {
        if (strcmp(childInformation.childId, tempInformation.childId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&childInformation, sizeof(childInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&childInformation, sizeof(childInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&childInformation, sizeof(childInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("childInfo.bin");
    rename("temp.bin", "childInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tchild Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void searchchildInfo()
{
    FILE *fileOne = fopen("childInfo.bin", "rb");

    Child childInformation;

    int choice, flag = 0;
    char childId[20], childSassignment[10];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Search Student Information ======\n");

    printf("\n\t\t\tChoose your option :\n\t\t\t1.Search by child ID\n\t\t\t2.Search by section assignment .");
    printf("\n\n\t\t\tEnter Your Option : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("\t\t\t\t====== Search child Information ======\n");
        printf("\n\n\t\t\tEnter Child ID : ");
        getchar();
        gets(childId);
        while (fread(&childInformation, sizeof(childInformation), 1, fileOne) == 1)
        {
            if (strcmp(childInformation.childId, childId) == 0)
            {
                flag++;
                printf("\n\t\t\tChild first Name : %s\n\t\t\tChild last Name : %s\n\t\t\tChild ID  : %s\n\t\t\tChild Address : %s\n\t\t\tChild DOB : %s\n\t\t\tChild Section Assignment  : %s\n", childInformation.childFname, childInformation.childLname, childInformation.childId,
                 childInformation.childAddress,childInformation.childDob,childInformation.childSassignment);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tChild Id is not found");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\t\t\t\t====== Search Child Information ======\n");
        printf("\n\n\t\t\tEnter Child Section Assignment : ");
        getchar();
        gets(childSassignment);
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "First Name","Last Name", "ID", "Address", "DOB", "Section Assignment");
        printf("\t\t---------------------------------------------------------------------------------------------------------");
        while (fread(&childInformation, sizeof(childInformation), 1, fileOne) == 1)
        {
            if (stricmp(childInformation.childSassignment, childSassignment) == 0)
            {
                flag++;
                printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", childInformation.childFname,childInformation.childLname, childInformation.childId, childInformation.childAddress, childInformation.childDob, childInformation.childSassignment);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tChild Id is not found");
        }
    }
    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fileOne);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}
//==========================================================Program for Parent or Guardian  Account=======================================================

void parentInfo()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\t\t====== Child Management Database System ======\n");
        printf("\n\t\t\t1. Create Parent or Guardian Account");
        printf("\n\t\t\t2. Display Parent or Guardian Information");
        printf("\n\t\t\t3. Update Parent or Guardian Information");
        printf("\n\t\t\t4. Delete Parent or Guardian Information");
        printf("\n\t\t\t5. Search Parent or Guardian Information");
        printf("\n\t\t\t6. List Parent and their child Information");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            createparentAccount();
            break;
        case '2':
            displayparentInfo();
            break;
        case '3':
            updateparentInfo();
            break;
        case '4':
            deleteparentInfo();
            break;
        case '5':
            searchparentInfo();
            break;
            break;
        case '6':
            //listparentnchild();
        case '0':
            printf("\n\t\t\t====== Thank You ======");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }

}


void createparentAccount()
{
    FILE *fileOne = fopen("ParentInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Parent parentInformation;

    system("cls");

    printf("\t\t\t====== Create Parent OR Guardian Record ======\n");

    printf("\n\t\t\tEnter Parent's First Name : ");
    getchar();
    gets(parentInformation.parentFname);

    printf("\n\t\t\tEnter Parent's Last Name : ");
    getchar();
    gets(parentInformation.parentLname);
    printf("\n\t\t\tEnter Parent's ID : ");
    gets(parentInformation.guardianId);
    printf("\n\t\t\tEnter Parent's (Relationship) : ");
    gets(parentInformation.parentRelationship);
    printf("\n\t\t\tEnter Parent's Address : ");
    gets(parentInformation.parentAddress);
    printf("\n\t\t\tEnter Parent Telephone No : ");
    gets(parentInformation.parentTno);
    printf("\n\t\t\tEnter Parent's Email Address : ");
    gets(parentInformation.parentEmail);



    fwrite(&parentInformation, sizeof(parentInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

//=====================================Display all parents record================================================


void displayparentInfo()
{
    FILE *fileOne = fopen("ParentInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Parent parentInformation;

    system("cls");

    printf("\t\t\t\t====== All Parent Information ======\n");

    printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "First Name","Last Name", "ID", "Address", "Telephone No", "Email");
    printf("\t\t--------------------------------------------------------------------------------------------------------------------------------------------------");

    while (fread(&parentInformation, sizeof(parentInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", parentInformation.parentFname, parentInformation.parentLname, parentInformation.guardianId,parentInformation.parentAddress,parentInformation.parentTno,parentInformation.parentEmail);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}


void updateparentInfo()
{
    FILE *fileOne = fopen("ParentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Parent parentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Update parents Information ======\n");

    printf("\n\t\t\tEnter Parent's ID : ");
    getchar();
    gets(tempInformation.guardianId);

    while (fread(&parentInformation, sizeof(parentInformation), 1, fileOne) == 1)
    {
        if (strcmp(parentInformation.guardianId, tempInformation.guardianId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Parent's first Name\n\t\t\t2.Update Parent's last Name\n\t\t\t3.Update Parent Telephone No\n\t\t\t4.Update Parent's Address\n\t\t\t5.Update Parent's Email");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Parent's New First Name : ");
                getchar();
                gets(tempInformation.parentFname);
                strcpy(parentInformation.parentFname, tempInformation.parentFname);

                fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Parent's Last Name to Update: ");
                getchar();
                gets(tempInformation.parentLname);
                strcpy(parentInformation.parentLname, tempInformation.parentLname);

                fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Parent's Telephone No to Update: ");
                getchar();
                gets(tempInformation.parentTno);
                strcpy(parentInformation.parentTno, tempInformation.parentTno);

                fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter  child's Address to Update: ");
                getchar();
                gets(tempInformation.parentAddress);
                strcpy(parentInformation.parentAddress, tempInformation.parentAddress);

                fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Parent's Email to Update: ");
                getchar();
                gets(tempInformation.parentEmail);
                strcpy(parentInformation.parentEmail, tempInformation.parentEmail);

                fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("ParentInfo.bin");
    rename("temp.bin", "ParentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tNo info");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}



void deleteparentInfo()
{
    FILE *fileOne = fopen("ParentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Parent parentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Delete Parent Information ======\n");

    printf("\n\t\t\tEnter Parent's ID : ");
    getchar();
    gets(tempInformation.guardianId);

    while (fread(&parentInformation, sizeof(parentInformation), 1, fileOne) == 1)

    {
        if (strcmp(parentInformation.guardianId, tempInformation.guardianId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&parentInformation, sizeof(parentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("ParentInfo.bin");
    rename("temp.bin", "ParentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tchild Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void searchparentInfo()
{
    FILE *fileOne = fopen("ParentInfo.bin", "rb");

    Parent parentInformation;

    int flag = 0;
    char guardianId[20];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }
    else
    {
         system("cls");
        printf("\t\t\t\t====== Search for Individual Parent Information ======\n");
        printf("\n\n\t\t\tEnter Parent ID : ");
        getchar();
        gets(guardianId);
        while (fread(&parentInformation, sizeof(parentInformation), 1, fileOne) == 1)
        {
            if (strcmp(parentInformation.guardianId, guardianId) == 0)
            {
                flag++;
                printf("\n\t\t\tParent first Name : %s\n\t\t\tParent last Name : %s\n\t\t\tParent Id  : %s\n\t\t\tParent Address : %s\n\t\t\tParent Telephone No : %s\n\t\t\tParent Email : %5s\n", parentInformation.parentFname, parentInformation.parentLname, parentInformation.guardianId, parentInformation.parentAddress, parentInformation.parentTno,
                   parentInformation.parentEmail );
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tParent Id is not found");
        }

     }



    fclose(fileOne);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}
//======================================== List of parent and children==========================================================
/**void listparentnchild()
{
    FILE *fileOne = fopen("ParentInfo.bin", "rb");
    FILE *temp = fopen("ChildInfo.bin", "rb");

    Parent parentInformation;
    Child  childInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Parents and kids Information ======\n");

    printf("\n\t\t\tEnter Parent's ID : ");
    getchar();
    gets(childInformation.childPid);

    while (fread(&childInformation, sizeof(childInformation), 1, temp) == 1)
    {
        if (strcmp(childInformation.childPid, parentInformation.guardianId) == 0)
        {
             flag++;
            printf("\n\t\t\tChild first Name : %s\n\t\t\tChild last Name : %s\n\t\t\tParent First Name  : %s\n\t\t\tParent Last Name:  %s\n", childInformation.childFname, childInformation.childLname, parentInformation.parentFname,parentInformation.parentLname);
        }
        else
        {
            printf("\n\t\t\tsomething is wrong");
        }
    }
     if (flag == 0)
        {
            printf("\n\t\t\tParent Id is not found");
        }

}
**/

//================================================== Program for Caregiver Record=======================================================

void caregiverInfo()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\t\t====== Child Management Database System ======\n");
        printf("\n\t\t\t1. Create Caregiver Record");
        printf("\n\t\t\t2. Display All Caregiver Information");
        printf("\n\t\t\t3. Update Caregiver Information");
        printf("\n\t\t\t4. Delete Caregiver Information");
        printf("\n\t\t\t5. Search Caregiver Information");
        printf("\n\t\t\t6. List of Caregiver Employed");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            createcaregiverAccount();
            break;
        case '2':
            displaycaregiverInfo();
            break;
        case '3':
            updatecaregiverInfo();
            break;
        case '4':
            deletecaregiverInfo();
            break;
        case '5':
            searchcaregiverInfo();
            break;
        case '6':
            listcaregiverInfo();
            break;
        case '0':
            printf("\n\t\t\t====== Thank You ======");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }

}
void createcaregiverAccount()
{
    FILE *fileOne = fopen("CaregiverInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Caregiver caregiverInformation;

    system("cls");

    printf("\t\t\t====== Create Caregiver Record ======\n");

    printf("\n\t\t\tEnter Caregiver's First Name : ");
    getchar();
    gets(caregiverInformation.caregiverFname);

    printf("\n\t\t\tEnter Caregiver's Last Name : ");
    getchar();
    gets(caregiverInformation.caregiverLname);
    printf("\n\t\t\tEnter Caregiver's ID : ");
    gets(caregiverInformation.caregiverId);
    printf("\n\t\t\tEnter Caregiver's Gender : ");
    gets(caregiverInformation.caregiverGender);
    printf("\n\t\t\tEnter Caregiver's Address : ");
    gets(caregiverInformation.caregiverAddress);
    printf("\n\t\t\tEnter Caregiver Age Range : ");
    gets(caregiverInformation.caregiverArange);
    printf("\n\t\t\tEnter Caregiver Section Assignment : ");
    gets(caregiverInformation.caregiverSassignment);



    fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}


//=====================================Display all caregiver record======================================================
void displaycaregiverInfo()
{
    FILE *fileOne = fopen("CaregiverInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Caregiver caregiverInformation;

    system("cls");

    printf("\t\t\t\t====== All Caregiver Information ======\n");

    printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "First Name","Last Name", "ID", "Age Range", "Address", "Section Assignment");
    printf("\t\t--------------------------------------------------------------------------------------------------------------------------------------------------");

    while (fread(&caregiverInformation, sizeof(caregiverInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", caregiverInformation.caregiverFname, caregiverInformation.caregiverLname, caregiverInformation.caregiverId,caregiverInformation.caregiverArange,caregiverInformation.caregiverAddress,caregiverInformation.caregiverSassignment);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

//============================================Update caregiver record=======================================================================


void updatecaregiverInfo()
{
    FILE *fileOne = fopen("CaregiverInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Caregiver caregiverInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Update caregiver Information ======\n");

    printf("\n\t\t\tEnter Caregiver's ID : ");
    getchar();
    gets(tempInformation.caregiverId);

    while (fread(&caregiverInformation, sizeof(caregiverInformation), 1, fileOne) == 1)
    {
        if (strcmp(caregiverInformation.caregiverId, tempInformation.caregiverId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Caregiver's first Name\n\t\t\t2.Update Caregiver's last Name\n\t\t\t3.Update Caregiver Age Range\n\t\t\t4.Update Caregiver's Address\n\t\t\t5.Update Section Assignment");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Caregiver's New First Name : ");
                getchar();
                gets(tempInformation.caregiverFname);
                strcpy(caregiverInformation.caregiverFname, tempInformation.caregiverFname);

                fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Caregiver's Last Name to Update: ");
                getchar();
                gets(tempInformation.caregiverLname);
                strcpy(caregiverInformation.caregiverLname, tempInformation.caregiverLname);

                fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Caregiver's Age Range to Update: ");
                getchar();
                gets(tempInformation.caregiverArange);
                strcpy(caregiverInformation.caregiverArange, tempInformation.caregiverArange);

                fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter  Caregiver's Address to Update: ");
                getchar();
                gets(tempInformation.caregiverAddress);
                strcpy(caregiverInformation.caregiverAddress, tempInformation.caregiverAddress);

                fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Caregiver's Section Assignment to Update: ");
                getchar();
                gets(tempInformation.caregiverSassignment);
                strcpy(caregiverInformation.caregiverSassignment, tempInformation.caregiverSassignment);

                fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("CaregiverInfo.bin");
    rename("temp.bin", "CaregiverInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tNo info");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}


//=====================================delete caregiver record===========================================
void deletecaregiverInfo()
{
    FILE *fileOne = fopen("CaregiverInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Caregiver caregiverInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Delete Caregiver Information ======\n");

    printf("\n\t\t\tEnter Caregiver's ID : ");
    getchar();
    gets(tempInformation.caregiverId);

    while (fread(&caregiverInformation, sizeof(caregiverInformation), 1, fileOne) == 1)
    {
        if (strcmp(caregiverInformation.caregiverId, tempInformation.caregiverId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&caregiverInformation, sizeof(caregiverInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("CaregiverInfo.bin");
    rename("temp.bin", "CaregiverInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tCaregiver Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}
//==================================================================search for specific caregiver records==================================

void searchcaregiverInfo()
{
    FILE *fileOne = fopen("CaregiverInfo.bin", "rb");

    Caregiver caregiverInformation;

    int choice, flag = 0;
    char caregiverId[20], caregiverSassignment[10];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Search caregiver Information ======\n");

    printf("\n\t\t\tChoose your option :\n\t\t\t1.Search by caregiver ID\n\t\t\t2.Search by section assignment .");
    printf("\n\n\t\t\tEnter Your Option : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("\t\t\t\t====== Search caregiver Information ======\n");
        printf("\n\n\t\t\tEnter Caregiver ID : ");
        getchar();
        gets(caregiverId);
        while (fread(&caregiverInformation, sizeof(caregiverInformation), 1, fileOne) == 1)
        {
            if (strcmp(caregiverInformation.caregiverId, caregiverId) == 0)
            {
                flag++;
                printf("\n\t\t\tCaregiver first Name : %s\n\t\t\tCaregiver last Name : %s\n\t\t\tCaregiver ID  : %s\n\t\t\tCaregiver Gender : %s\n\t\t\tCaregiver Address : %s\n\t\t\tCaregiver Age Range : %s\n\t\t\tCaregiver Section Assignment  : %s\n", caregiverInformation.caregiverFname, caregiverInformation.caregiverLname, caregiverInformation.caregiverId,
                 caregiverInformation.caregiverGender,caregiverInformation.caregiverAddress,caregiverInformation.caregiverArange,caregiverInformation.caregiverSassignment);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tcaregiver Id is not found");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\t\t\t\t====== Search caregiver Information ======\n");
        printf("\n\n\t\t\tEnter caregiver Section Assignment : ");
        getchar();
        gets(caregiverSassignment);
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "First Name","Last Name", "ID", "Address", "Age Range", "Section Assignment");
        printf("\t\t---------------------------------------------------------------------------------------------------------");
        while (fread(&caregiverInformation, sizeof(caregiverInformation), 1, fileOne) == 1)
        {
            if (stricmp(caregiverInformation.caregiverSassignment, caregiverSassignment) == 0)
            {
                flag++;
                printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", caregiverInformation.caregiverFname,caregiverInformation.caregiverLname, caregiverInformation.caregiverId, caregiverInformation.caregiverAddress, caregiverInformation.caregiverArange, caregiverInformation.caregiverSassignment);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tNo section found");
        }
    }
    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fileOne);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void listcaregiverInfo()
{
     FILE *fileOne = fopen("CaregiverInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Caregiver caregiverInformation;

    system("cls");

    printf("\t\t\t\t====== All Caregiver Employed ======\n");

    printf("\n\n\t\t%-20s%-13s%-s\n", "First Name","Last Name", "ID");
    printf("\t\t-------------------------------------------------------------");

    while (fread(&caregiverInformation, sizeof(caregiverInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-s\n", caregiverInformation.caregiverFname, caregiverInformation.caregiverLname, caregiverInformation.caregiverId);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}
