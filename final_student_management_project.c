#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[20];
    char fathername[20];
    int age;
    char course[20];
    char branch[20];
    int marks1, marks2, marks3, marks4, marks5;
    float attendance;
    char phoneNo[15];
};

void addstudent();
void viewstudent();
void searchstudent();
void updatestudent();
void deletestudent();
void countstudents();

int main() {
    int ch;
    while (1) {
        printf("\nSTUDENT MANAGEMENT SYSTEM");
        printf("\n1. Add student");
        printf("\n2. View students");
        printf("\n3. Search student");
        printf("\n4. Update student");
        printf("\n5. Delete student");
        printf("\n6. Count students");
        printf("\n7. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addstudent();
                break;
            case 2:
                viewstudent();
                break;
            case 3:
                searchstudent();
                break;
            case 4:
                updatestudent();
                break;
            case 5:
                deletestudent();
                break;
            case 6:
                countstudents();
                break;
            case 7:
            	exit(0);
            default:
                printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}

void addstudent() {
    FILE *fp;
    struct student s;
    fp = fopen("student.info", "ab");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    printf("\nEnter the roll number: ");
    scanf("%d", &s.roll);

    printf("Enter the student name: ");
    scanf("%19s", s.name);

    printf("Enter the father's name: ");
    scanf("%19s", s.fathername);

    printf("Enter the age of student: ");
    scanf("%d", &s.age);

    printf("Enter the course: ");
    scanf("%19s", s.course);

    printf("Enter the branch: ");
    scanf("%19s", s.branch);

    printf("Enter the Mathematics marks: ");
    scanf("%d", &s.marks1);

    printf("Enter the Physics marks: ");
    scanf("%d", &s.marks2);

    printf("Enter the English marks: ");
    scanf("%d", &s.marks3);

    printf("Enter the Python marks: ");
    scanf("%d", &s.marks4);

    printf("Enter the UHV marks: ");
    scanf("%d", &s.marks5);

    printf("Enter the attendance of student: ");
    scanf("%f", &s.attendance);

    printf("Enter the mobile number: ");
    scanf("%14s", s.phoneNo);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("\nSTUDENT ADDED SUCCESSFULLY\n");
}

void viewstudent() {
    FILE *fp;
    struct student s;
    fp = fopen("student.info", "rb");

    if (fp == NULL) {
        printf("\nNo record found\n");
        return;
    }

    printf("\n\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("\nRoll No.: %d", s.roll);
        printf("\nName: %s", s.name);
        printf("\nFather Name: %s", s.fathername);
        printf("\nAge: %d", s.age);
        printf("\nCourse: %s", s.course);
        printf("\nBranch: %s", s.branch);
        printf("\nMaths: %d", s.marks1);
        printf("\nPhysics: %d", s.marks2);
        printf("\nEnglish: %d", s.marks3);
        printf("\nPython: %d", s.marks4);
        printf("\nUHV: %d", s.marks5);

        float total = (float)(s.marks1 + s.marks2 + s.marks3 + s.marks4 + s.marks5);
        printf("\nTotal Marks: %.2f", total);
        float percentage = (total / 500) * 100;
        printf("\nPercentage: %.2f%%", percentage);
        printf("\nCGPA: %.2f", percentage / 10);
        
        if(percentage>=90 && percentage<100){
           printf("\nGrade:A+");
       }
        else if(percentage>=80 && percentage<90){
        	printf("\nGrade:A");	
		}
		else if(percentage>=70 && percentage<80){
           printf("\nGrade:B+");
       }
       else if(percentage>=60 && percentage<70){
       	printf("\nGrade:B");
	   }
	   else if(percentage>=50 && percentage<60){
	   	printf("\nGrade:c");
	   }
	   else{
	   	printf("\nGrade:D");
	   }
	   
	   if(s.marks1>=33 && s.marks2>=33 && s.marks3>=33 && s.marks4>=33 && s.marks5>=33){
	   	printf("\nRESULT:PASS");
	   }
	   else{
	   	printf("\nRESULT:FAIL");
	   }
	   
	    printf("\nAttendance: %.2f%%", s.attendance);
        printf("\nPhone Number: %s", s.phoneNo);
        printf("\n----------------------------------------------\n");
    }
    fclose(fp);
}

void searchstudent() {
    FILE *fp;
    struct student s;
    int roll, found = 0;
    fp = fopen("student.info", "rb");

    if (fp == NULL) {
        printf("\nNo record found\n");
        return;
    }

    printf("\nEnter the roll number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("\n--- Student Found! ---\n");
            printf("\nRoll No.: %d", s.roll);
            printf("\nName: %s", s.name);
            printf("\nFather Name: %s", s.fathername);
            printf("\nAge: %d", s.age);
            printf("\nCourse: %s", s.course);
            printf("\nBranch: %s", s.branch);
            printf("\nMaths: %d", s.marks1);
            printf("\nPhysics: %d", s.marks2);
            printf("\nEnglish: %d", s.marks3);
            printf("\nPython: %d", s.marks4);
            printf("\nUHV: %d", s.marks5);
            
            float total = (float)(s.marks1 + s.marks2 + s.marks3 + s.marks4 + s.marks5);
            float percentage = (total / 500) * 100;

            printf("\nTotal Marks: %.2f", total);
            printf("\nPercentage: %.2f%%", percentage);
            printf("\nCGPA: %.2f", percentage / 10);

            if (percentage >= 90 && percentage <= 100)
                printf("\nGrade: A+");
            else if (percentage >= 80)
                printf("\nGrade: A");
            else if (percentage >= 70)
                printf("\nGrade: B+");
            else if (percentage >= 60)
                printf("\nGrade: B");
            else if (percentage >= 50)
                printf("\nGrade: C");
            else
                printf("\nGrade: D");

            if (s.marks1 >= 33 && s.marks2 >= 33 && s.marks3 >= 33 && s.marks4 >= 33 && s.marks5 >= 33){
			
                printf("\nRESULT: PASS");
            }
            else{
                printf("\nRESULT: FAIL");
            }


            
            printf("\nAttendance: %.2f%%", s.attendance);
            printf("\nPhone Number: %s\n", s.phoneNo);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found\n");
    }
    fclose(fp);
}

void updatestudent() {
    FILE *fp, *temp;
    struct student s;
    int roll, found = 0;

    fp = fopen("student.info", "rb");
    temp = fopen("temp.info", "wb");
    if(fp==NULL){
        printf("\nNO RECORD FOUND");
        return;
    }
    printf("\nEnter the roll number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            found = 1;
            printf("\nEnter new roll number: ");
            scanf("%d", &s.roll);

            printf("Enter new student name: ");
            scanf("%19s", s.name);

            printf("Enter new father's name: ");
            scanf("%19s", s.fathername);

            printf("Enter new age: ");
            scanf("%d", &s.age);

            printf("Enter new course: ");
            scanf("%19s", s.course);

            printf("Enter new branch: ");
            scanf("%19s", s.branch);

            printf("Enter new Mathematics marks: ");
            scanf("%d", &s.marks1);

            printf("Enter new Physics marks: ");
            scanf("%d", &s.marks2);

            printf("Enter new English marks: ");
            scanf("%d", &s.marks3);

            printf("Enter new Python marks: ");
            scanf("%d", &s.marks4);

            printf("Enter new UHV marks: ");
            scanf("%d", &s.marks5);

            printf("Enter new attendance: ");
            scanf("%f", &s.attendance);

            printf("Enter new mobile number: ");
            scanf("%14s", s.phoneNo);
        }
        fwrite(&s, sizeof(s), 1, temp);
    }
    fclose(fp);
    fclose(temp);

    remove("student.info");
    rename("temp.info", "student.info");

    if (found) {
        printf("\nSTUDENT UPDATED SUCCESSFULLY\n");
    } else {
        printf("\nSTUDENT NOT FOUND\n");
    }
}

void deletestudent() {
    FILE *fp, *temp;
    struct student s;
    int roll, found = 0;

    fp = fopen("student.info", "rb");
    temp = fopen("temp.info", "wb");
    if(fp==NULL){
        printf("\nNO RECORD FOUND");
        return;
    }
    printf("\nEnter the roll number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            found = 1;
            continue;
            }
            fwrite(&s,sizeof(s),1,temp);
        }

        fclose(fp);
        fclose(temp);

        remove("student.info");
        rename("temp.info","student.info");

        if(found){
            printf("\nSTUDENT DELETED SUCCESSFULLY");
        }
        else{
            printf("\nSTUDENT NOT FOUND");
        }
    }
    
    
void countstudents()
{
    FILE *fp;
    struct student s;
    int count = 0;

    fp = fopen("student.info", "rb");

    if(fp == NULL)
    {
        printf("\nNO RECORD FOUND");
        return;
    }

    while(fread(&s, sizeof(s), 1, fp))
    {
        count++;
    }

    fclose(fp);

    printf("\nTotal Students = %d\n", count);
}