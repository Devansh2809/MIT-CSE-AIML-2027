#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int *month;
    int year;
} Dob;

typedef struct {
    int reg_no;
    char *name;
    char address[100];
} Stu_Info;

typedef struct {
    char *college_name;
    char university_name[100];
} College;

typedef struct {
    Dob *dob;
    Stu_Info *stu_info;
    College *college;
} Student;

void readDob(Dob *dob) {
    printf("Enter day of birth: ");
    scanf("%d", &dob->day);

    dob->month = (int*)malloc(sizeof(int));
    printf("Enter month of birth: ");
    scanf("%d", dob->month);

    printf("Enter year of birth: ");
    scanf("%d", &dob->year);
}

void readStu_Info(Stu_Info *stu_info) {
    printf("Enter registration number: ");
    scanf("%d", &stu_info->reg_no);

    stu_info->name = (char*)malloc(100 * sizeof(char));
    printf("Enter name: ");
    scanf(" %[^\n]", stu_info->name);

    printf("Enter address: ");
    scanf(" %[^\n]", stu_info->address);
}


void readCollege(College *college) {
    college->college_name = (char*)malloc(100 * sizeof(char));
    printf("Enter college name: ");
    scanf(" %[^\n]", college->college_name);
    printf("Enter university name: ");
    scanf(" %[^\n]", college->university_name);
}


void displayDob(Dob *dob) {
    printf("Date of Birth: %02d %02d %04d\n", dob->day, *dob->month, dob->year);
}


void displayStu(Stu_Info *stu_info) {
    printf("Registration Number: %d\n", stu_info->reg_no);
    printf("Name: %s\n", stu_info->name);
    printf("Address: %s\n", stu_info->address);
}


void displayCollege(College *college) {
    printf("College Name: %s\n", college->college_name);
    printf("University Name: %s\n", college->university_name);
}


void readStudent(Student *student) {
    student->dob = (Dob*)malloc(sizeof(Dob));
    student->stu_info = (Stu_Info*)malloc(sizeof(Stu_Info));
    student->college = (College*)malloc(sizeof(College));

    printf("Enter Student Details \n");
    readDob(student->dob);
    readStu_Info(student->stu_info);
    readCollege(student->college);
}


void displayStudent(Student *student) {
    printf("Student Details \n");
    displayDob(student->dob);
    displayStu(student->stu_info);
    displayCollege(student->college);
}

int main() {
    Student *student = (Student*)malloc(sizeof(Student));
    readStudent(student);
    displayStu(student);
    free(student->dob->month);
    free(student->stu_info->name);
    free(student->college->college_name);
    free(student->dob);
    free(student->stu_info);
    free(student->college);
    free(student);
    return 0;
}
