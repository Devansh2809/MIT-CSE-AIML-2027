#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int rollNumber;
    float CGPA;
} Student;

Student* accept() {
    Student* student = (Student*)malloc(sizeof(Student)); 
    if (student == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    printf("Enter name: ");
    scanf("%s", student->name);

    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter CGPA: ");
    scanf("%f", &student->CGPA);

    return student;
}

void display(Student* student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("CGPA: %.2f\n", student->CGPA);
}
void sort(Student** students, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (students[j]->rollNumber > students[j+1]->rollNumber) {
                Student* temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of students: \n");
    scanf("%d", &n);
    Student** stud = (Student**)malloc(n * sizeof(Student*));
    for (i = 0; i < n; i++) {
        printf("Entering details for student %d:\n", i + 1);
        stud[i] = accept();
    }
    sort(stud, n);
    printf("Sorted list of students by roll number:\n");
    for (i = 0; i < n; i++) {
        display(stud[i]);
    }
    for (i = 0; i < n; i++) {
        free(stud[i]);
    }
    free(stud);
    return 0;
}


