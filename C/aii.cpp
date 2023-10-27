#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>


int a, d, e, f, New, i, j, k, seek, pos, temp5,temp6,temp7,temp8,m,n,o;
char b[100], c[100], g[100], h[100], temp[90], temp2[100],temp4[100], buff[100], temp3[100], buff2[100], buff3[100],temp9[100],z[100];
fpos_t position;


struct info {
	char LogName[100]= " ";
	char LogPass[100] = " ";
	char Subjects[100] = " ";
	int Grades = 0;
	int CourseWork = 0;
	int ClassWork = 0;
	char Class[100] = " ";
	char Students[1000] = " ";
	char StudentsL[1000] = " ";
	char ID[100];

}data;

// this function records the student's info and averages it

void record() {
	printf("\t\t\t\t\tNo Spaces Within Program\n\nEnter teacher Name\n");
	scanf("%s", data.LogName);
	system("cls");
	printf("========================================================================================================================\t\t\t\t\t\t\t\tWelcome %s\n========================================================================================================================", data.LogName);
	FILE* pfile;
	if ((pfile = fopen("Reg.txt", "r")) == NULL) {
		New = 1; 
		printf("Set Password\n");
		scanf("%s", data.LogPass);
		system("cls");
		printf("Setting Pass");
		Sleep(1000);
		printf(".");
		system("color 6");
		Sleep(1000);
		printf(".");
		system("color 2");
		Sleep(1000);
		printf(".");
		system("color 3");
		Sleep(1000);
		system("cls");
		FILE* pfile;
		pfile = fopen("Reg.txt", "w");
		fprintf(pfile, "%s\n\n", data.LogPass);
		fclose(pfile);
	}
	printf("Enter Password\n");
	scanf("%s", data.LogPass);
	system("cls");
	printf("Verifying");
	Sleep(1000);
	printf(".");
	system("color 6");
	Sleep(700);
	printf(".");
	system("color 2");
	Sleep(700);
	printf(".");
	system("color 3");
	Sleep(700);
	system("cls");
	Sleep(900);
	pfile = fopen("Reg.txt", "r");
	while (fscanf(pfile, "%s", c) != EOF) {
		if (strcmp(c, data.LogPass) == 0) {

			printf("ACCEPTED\n");
			Sleep(1000);
			system("cls");
			break;
		}
		else {
			system("color 4");
			printf("INCORRECT\n");
			while (strcmp(c, data.LogPass) != 0) {
				printf("Invalid...\n");
				Sleep(600);
				system("cls");
				printf("Retry\n");
				//printf("%s   ---- present=%s\n", data.LogPass, c);
				scanf("%s", data.LogPass);

			}
			system("cls");
			printf("Verifying");
			Sleep(1000);
			printf(".");
			system("color 6");
			Sleep(700);
			printf(".");
			system("color 2");
			Sleep(700);
			printf(".");
			system("color 3");
			Sleep(700);
			system("cls");
			Sleep(900);
			printf("ACCEPTED\n");
			system("cls");
			break;
		}
	} 

	fclose(pfile);
	fopen("Reg.txt", "a+");
	if (New == 1) {
		fprintf(pfile, " Students         Grade       Class     Subject      TestGrade1  TestGrade2   Final Average\n");
		New = 0; fgetpos(pfile, &position);
	}

	printf("Enter Student's First Name\n");
	scanf("%s", data.Students);
	system("cls");
	printf("Student :%s\n\n", data.Students);
	printf("Enter Last Name\n");
	scanf(" %s", data.StudentsL);
	strcpy(temp3, data.Students);
	strcat(temp3, buff2);
	strcat(temp3, data.StudentsL);
	fprintf(pfile, "%-1s %-20s", data.Students,data.StudentsL);
	system("cls");
	printf("Student :%s %s\n\n", data.Students, data.StudentsL);
	printf("Enter Form, Eg 12 or 13\n");
	scanf(" %i", &data.Grades);
	fprintf(pfile, "%-12i", data.Grades);
	system("cls");
	printf("Student : %s %s\nGrade :%i\n\n", data.Students, data.StudentsL, data.Grades);
	printf("Enter Class, Eg 1,2 or 3\n");
	scanf(" %s", &data.Class);
	fprintf(pfile, "%-7s", data.Class);
	system("cls");
	printf("Student : %s %s\nGrade :%i\nClass :%s\n\n", data.Students, data.StudentsL, data.Grades, data.Class);
	printf("Enter Subject\n");
	scanf("%s", data.Subjects);
	fprintf(pfile, " %-17s", data.Subjects);
	system("cls");
	printf("Student : %s %s\nGrade :%i\nClass :%s\nSubject:%s\n\n", data.Students, data.StudentsL, data.Grades, data.Class, data.Subjects);
	back:
	if (data.ClassWork && data.CourseWork != 0) {
		goto skip;
	}
	printf("Choose Marks 1.CourseWork\n             2.ClassWork\n             or 0 to skip\n");
	fflush(stdout);
	scanf("%i", &d);
	switch (d) {
	case 0: break;
	case 1: if (data.CourseWork == 0) {
		printf("Enter CourseWork Mark\n");
		scanf("%i", &data.CourseWork);
		fprintf(pfile, "%-12i", data.CourseWork);
		goto back;
	}
		  printf("\nCourseWork Already Entered\n");
		  Sleep(1000);
		  system("cls");
		  printf("Student : %s %s\nGrade :%i\nClass :%s\nSubject:%s\n\n", data.Students, data.StudentsL, data.Grades, data.Class, data.Subjects);
		  goto back;
	case 2: if (data.ClassWork == 0) {
		printf("Enter Classwork Mark\n");
		scanf("%i", &data.ClassWork);
		if (data.CourseWork == NULL) {
			fprintf(pfile,"%i\n",data.ClassWork); goto back;
		}
		else {
			fprintf(pfile, "%-14i", data.ClassWork); goto back;
		}
	} 
	printf("\nCourseWork Already Entered\n");
	Sleep(1000);
	system("cls");
	printf("Student : %s %s\nGrade :%i\nClass :%s\nSubject:%s\n\n", data.Students, data.StudentsL, data.Grades, data.Class, data.Subjects);
	goto back;
	default: printf("Invalid\n"); goto back;
	}
skip:

	fprintf(pfile, "%-20i", (data.ClassWork + data.CourseWork) / 2);
	fprintf(pfile, "\n");
	printf("========================================================================================================================     Student         ||    Grade  ||  Class ||     Subject    || Grade 1    || Grade2    ||    Average\n======================================================================================================================== ");
	printf("   %s %s               %i          %s        %s          %i          %i              %i\n\n\n", data.Students, data.StudentsL, data.Grades, data.Class, data.Subjects,data.ClassWork, data.CourseWork, (data.ClassWork + data.CourseWork) /2);
	data.ClassWork = 0; data.CourseWork = 0;
	fclose(pfile);


}
    //This function searches the file and allows you to edit the info on the file
void Search() {
	FILE* pfile;
	if ((pfile = fopen("Reg.txt", "r")) == NULL) {
		printf("Invalid File, Please Enter Data 1st\n");

	}
	else {
		FILE* pfile;
		//FILE* pfile2;
		system("cls");
		printf("Enter Student Name To Search\n");
		scanf("%s", h);
		seek = strlen(h);
		pfile = fopen("Reg.txt", "r+");
		while (fscanf(pfile, "%s", g) != EOF) {
			if (strcmp(g, h) == 0) {
				system("cls");
				printf("Searching");
				Sleep(1000);
				printf(".");
				system("color 6");
				Sleep(700);
				printf(".");
				system("color 2");
				Sleep(700);
				printf(".");
				system("color 3");
				Sleep(700);
				system("cls");
				Sleep(900);
				printf("Found");
				Sleep(1000);
				system("cls");
				fseek(pfile, -seek, SEEK_CUR);
				fscanf(pfile, "%s", temp);
				fscanf(pfile, "%s", temp2);
				fscanf(pfile, "%i", &temp5);
				fscanf(pfile, "%s", temp4);
				fscanf(pfile, "%s", temp9);
				fscanf(pfile, "%i", &temp6);
				fscanf(pfile, "%i", &temp7);
				fscanf(pfile, "%i", &temp8);
				fclose(pfile);
				//fgets(temp,seek + 1, pfile);
				//fgets(temp2, 90, pfile);
				pos = strlen(temp);
				pos = pos + strlen(temp2);
				//fseek(pfile, -2, SEEK_CUR);
				//fseek(pfile, -pos, SEEK_CUR);
				printf("Students              Grade       Class       Sub        TestGrade1 TestGrade2  Final Average\n");
				printf("%s %-20s%-12i%-7s%-17s%-12i%-7i%i\n", temp, temp2, temp5, temp4, temp9, temp6, temp7, temp8);
				printf("\n1.)Edit\n2.)Go Back  <-- \n3.)Exit\n");
				scanf("%i", &e);
				switch (e) {
				case 1:

					printf("Edit : 1.)1St Name\n       2.)Surname\n       3.)Grade\n       4.)Class\n       5.)Subject\n       6.)Test1\n       7.)Test2\n");
					scanf("%i", &e);
					switch (e) {
					case 1:
						printf("Enter New FirstName\n");
						scanf("%s\n", buff);
						printf("Confirm\n");
						pfile = fopen("Reg.txt", "r+");
						while (fscanf(pfile, "%s", g) != EOF) {
							if (strcmp(g, h) == 0) {
								fseek(pfile, -seek, SEEK_CUR);
								fprintf(pfile, "%s %-20s%-12i%-7s%-17s %-10i %-15i %i", buff, temp2, temp5, temp4, temp9, temp6, temp7, temp8);
								printf("Changed...\n");
								fclose(pfile);
								break;
							}
						} exit(0);



					case 2:
						printf("Enter New LastName\n");
						scanf("%s\n", temp2);
						printf("Confirm\n");
						pfile = fopen("Reg.txt", "r+");
						while (fscanf(pfile, "%s", g) != EOF) {
							if (strcmp(g, h) == 0) {
								fseek(pfile, -seek, SEEK_CUR);
								fprintf(pfile, "%s %-20s%-12i%-7s%-17s %-10i %-15i %i", h, temp2, temp5, temp4, temp9, temp6, temp7, temp8);
								printf("Changed...\n");
								fclose(pfile);
								break;
							}
						} exit(0);

					case 3:
						printf("Enter New Grade\n");
						scanf("%i\n", &temp5);
						printf("Confirm\n");
						pfile = fopen("Reg.txt", "r+");
						while (fscanf(pfile, "%s", g) != EOF) {
							if (strcmp(g, h) == 0) {
								fseek(pfile, -seek, SEEK_CUR);
								fprintf(pfile, "%s %-20s%-12i%-7s%-17s %-10i %-15i %i", h, temp2, temp5, temp4, temp9, temp6, temp7, temp8);
								printf("Changed...\n");
								fclose(pfile);
								break;
							}
						} exit(0);

					case 4:
						printf("Enter New Class\n");
						scanf("%s\n", temp4); 
						printf("Confirm\n");
						pfile = fopen("Reg.txt", "r+");
						while (fscanf(pfile, "%s", g) != EOF) {
							if (strcmp(g, h) == 0) {
								fseek(pfile, -seek, SEEK_CUR);
								fprintf(pfile, "%s %-20s%-12i%-7s%-17s %-10i %-15i %i", h, temp2, temp5, temp4, temp9, temp6, temp7, temp8);
								printf("Changed...\n");
								fclose(pfile);
								break;
							}
						} exit(0);

					case 5:
						printf("Enter New Subject\n");
						scanf("%s\n", &temp9);
						printf("Confirm\n");
						pfile = fopen("Reg.txt", "r+");
						while (fscanf(pfile, "%s", g) != EOF) {
							if (strcmp(g, h) == 0) {
								fseek(pfile, -seek, SEEK_CUR);
								fprintf(pfile, "%s %-20s%-12i%-7s%-17s %-10i %-15i %i", h, temp2, temp5, temp4, temp9, temp6, temp7, temp8);
								printf("Changed...\n");
								fclose(pfile);
								break;
							}
						} exit(0);



					case 6:
						printf("Enter New TestGrade1\n");
						scanf("%i\n", &temp6);
						printf("Confirm\n");
						temp8 = (temp6 + temp7) / 2;
						pfile = fopen("Reg.txt", "r+");
						while (fscanf(pfile, "%s", g) != EOF) {
							if (strcmp(g, h) == 0) {
								fseek(pfile, -seek, SEEK_CUR);
								fprintf(pfile, "%s %-20s%-12i%-7s%-17s %-10i %-15i %i", h, temp2, temp5, temp4, temp9, temp6, temp7, temp8);
								printf("Changed...\n");
								fclose(pfile);
								break;
							}
						} exit(0);

					case 7:
						printf("Enter New TestGrade2\n");
						scanf("%i\n", &temp7);
						printf("Confirm\n");
						temp8 = (temp6 + temp7) / 2;
						pfile = fopen("Reg.txt", "r+");
						while (fscanf(pfile, "%s", g) != EOF) {
							if (strcmp(g, h) == 0) {
								fseek(pfile, -seek, SEEK_CUR);
								fprintf(pfile, "%s %-20s%-12i%-7s%-17s %-10i %-15i %i", h, temp2, temp5, temp4, temp9, temp6, temp7, temp8);
								printf("Changed...\n");
								fclose(pfile);
								break;
							}
						} exit(0);
					}
				}
			}
			printf("Name Not Found\n");
		}
	}
}
   //this menu function allows you to either select the option to record info, search or exit
void Menu() {
Men:
	printf("========================================================================================================================\t\t\t\t\t\t\tReg Program\n========================================================================================================================\n\n1.)Enter Student Data\n2.)Search For Student\n3.)Exit\n");
	scanf("%s", buff3);
	if (strcmp(buff3, "1") == 0) {
		e = 1;
	}
	if (strcmp(buff3, "2") == 0) {
		e = 2;
	}
	if (strcmp(buff3, "3") == 0) {
		e = 3;
	}
	switch (e) {
	case 1:  system("cls");
		record(); j = 1;
		goto Men;
	case 2:  system("cls");
		Search(); goto Men;
	case 3: exit(0);
		
	} 
	printf("Invalid...\n");
	Sleep(1000);
	system("cls");
	goto Men;
}




//start of the program, menu function is called 

int main() {

	Menu();



}

