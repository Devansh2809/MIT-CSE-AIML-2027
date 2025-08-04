#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} DateOfBirth;
typedef struct {
    int houseNumber;
    int zipCode;
    char state[100];
} Address;
typedef struct {
    char name[100];
    DateOfBirth dob;
    Address address;
} Employee;
void read(Employee* employee) {
    printf("Enter the name of the employee: ");
    scanf("%s", employee->name);

    printf("Enter the date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &employee->dob.day, &employee->dob.month, &employee->dob.year);

    printf("Enter the house number: ");
    scanf("%d", &employee->address.houseNumber);

    printf("Enter the zip code: ");
    scanf("%d", &employee->address.zipCode);

    printf("Enter the state: ");
    scanf(" %[^\n]", employee->address.state);
}
void display(Employee* employee) {
    printf("Employee Name: %s\n", employee->name);
    printf("Date of Birth: %d %d %d\n", employee->dob.day, employee->dob.month, employee->dob.year);
    printf("Address: House No. %d, Zip Code: %d, State: %s\n", employee->address.houseNumber, employee->address.zipCode, employee->address.state);
}
int main() {
    int n, i;

    printf("Enter the number of employees: ");
    scanf("%d", &n);
    Employee* emp = (Employee*)malloc(n * sizeof(Employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    for (i = 0; i < n; i++) {
        printf("Entering details for employee %d:\n", i + 1);
        read(&emp[i]);
    }
    printf("Displaying employee details:\n");
    for (i = 0; i < n; i++) {
        display(&emp[i]);
    }
    free(emp);
    return 0;
}




